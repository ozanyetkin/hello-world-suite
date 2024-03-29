Monitors = {}
MinX, MinY = 0, 0

function Initialize()
	resources = SKIN:GetVariable('@')
	skinsPath = SKIN:GetVariable('SKINSPATH')
    if not SKIN:GetVariable('Config') then
        SKIN:Bang('!DeactivateConfig')
        return
    end
    local w, h = tonumber(SKIN:GetVariable('VSCREENAREAWIDTH', 0)), tonumber(SKIN:GetVariable('VSCREENAREAHEIGHT', 0))
    local sw = SKIN:ParseFormula(SKIN:ReplaceVariables('(400*#CanvasScale#)'))
    local sh = SKIN:ParseFormula(SKIN:ReplaceVariables('(125*#CanvasScale#)'))
    local scale = math.min(sw/w, sh/h)
    SKIN:Bang('!SetVariable', 'Scale', scale)
end

function Update()
    Monitors = ListAvailableMonitors(SKIN:ReplaceVariables('[&AppBar:AvailableMonitors()]'))
    Generate()
    SetPriority(SKIN:GetVariable('PriorityList'))
end

function SplitString(inString, inDelimiter)
	assert(inDelimiter:len() == 1, 'SplitString: Delimiter may only be a single character')
	local outTable = {}
	for matchedString in inString:gmatch('[^%' .. inDelimiter .. ']+') do
		table.insert(outTable, matchedString)
	end
	return outTable
end

function ListAvailableMonitors(str)
    local outTable = {}
    MinX = 0
    MinY = 0
    for _, v in pairs(SplitString(str, ';')) do
        local monitorInfo = {}
        for key, value in pairs(SplitString(v, '|')) do
            if key == 1 then
                monitorInfo.x = tonumber(value)
                MinX = (monitorInfo.x < MinX) and monitorInfo.x or MinX
            elseif key == 2 then
                monitorInfo.y = tonumber(value)
                MinY = (monitorInfo.y < MinY) and monitorInfo.y or MinY
            elseif key == 3 then
                monitorInfo.w = tonumber(value)
            elseif key == 4 then
                monitorInfo.h = tonumber(value)
            elseif key == 5 then
                monitorInfo.id = value
            end
				SKIN:Bang('!SetVariable', 'Test', key)
        end
        table.insert(outTable, monitorInfo)
    end
    return outTable
end

function Generate()
    for k, v in pairs(Monitors) do
        local str = ''
        for _, token in pairs(SplitString('Rectangle ((' .. -MinX .. ' + $x$)*#Scale# + 20*#Scale#), ((' .. -MinY .. ' + $y$)*#Scale# + 20*#Scale#), ($w$*#Scale# - 20*#Scale#), ($h$*#Scale# - 20*#Scale#), (30*#Scale#) | StrokeWidth (0*#Scale#) | Extend Style$active$', '$')) do
            if token == 'x' then
                str = str .. v.x
            elseif token == 'y' then
                str = str .. v.y
            elseif token == 'w' then
                str = str .. v.w
            elseif token == 'h' then
                str = str .. v.h
            elseif token == 'active' then
                str = str .. '[#Monitor' .. v.id .. 'Active]'
                SKIN:Bang('!SetVariable', 'Monitor' .. v.id .. 'Active', 0)
            else
                str = str .. token
            end
        end
        SKIN:Bang('!SetOption', 'Monitors', 'Shape' .. k + 1, str)
		SKIN:Bang('!SetVariable', 'NumberOfMonitors', k)
    end
    SKIN:Bang('!UpdateMeter', 'Monitors')
end

function SetPriority(id)
    for _, v in pairs(Monitors) do
        SKIN:Bang('!SetVariable', 'Monitor' .. v.id .. 'Active', 0)
    end
    if id then
        SKIN:Bang('!SetVariable', 'Monitor' .. id .. 'Active', 1)
        SKIN:Bang('!SetVariable', 'PriorityList', id)
        SKIN:Bang('!WriteKeyValue', 'Variables', 'DroptopPriorityList', id, resources..'GlobalVar\\UserSettings.inc')
        SKIN:Bang('!SetOption', 'MeasureAppBar', 'PriorityList', id, 'Droptop\\Other\\BackgroundProcesses')
        SKIN:Bang('!Hide', 'Droptop\\DropdownBar')
        SKIN:Bang('!CommandMeasure', 'MeasureAppBar', 'UpdatePosition', 'Droptop\\Other\\BackgroundProcesses')
        SKIN:Bang('!UpdateGroup', 'PrimaryConfig')
		SKIN:Bang('!ShowFade', 'Droptop\\DropdownBar')
    end
    SKIN:Bang('!UpdateMeter', '*')
    SKIN:Bang('!Redraw')
end

function HandleMouseAction(x, y)
    local scale = tonumber(SKIN:GetVariable('Scale', 0.1))
    x = x/scale + MinX
    y = y/scale + MinY
    for _, v in pairs(Monitors) do
        if x > v.x and x < v.x + v.w then
            if y > v.y and y < v.y + v.h then
                SKIN:Bang('!SetVariable', 'ButtonActive', 1)
                SetPriority(v.id)
            end
        end
    end
end

function SendResult()
    local config = SplitString(SKIN:GetVariable('Config'), '|')
    SKIN:Bang(
        '!CommandMeasure',
        config[1],
        'SelectionDone(\'' .. SKIN:GetVariable('PriorityList') .. '\')',
        config[2]
    )
    SKIN:Bang(
        '!WriteKeyValue',
        'Variables',
        'Config',
        ''
    )
    SKIN:Bang('!DeactivateConfig')
end