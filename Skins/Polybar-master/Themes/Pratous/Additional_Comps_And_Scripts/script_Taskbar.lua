function Initialize()
	dofile(SKIN:GetVariable('@')..'Scripts\\Taskbar_Common_Script.lua')
	GetEssentialVariables()
end

function Update()
	UpdateNow()
end

--This function is used for drawing subprocess tracking shape. 
--TotalRunning is total number of subprocess of 1 process.
--CurrentDrawingIndex is taskbar index of process that currently drawing.
--CurrentActiveWindow: Return true if currently drawing process is active. Return false if currently drawing process is not active process. 
--shapeCount is start at 2
-- If theme doesn't need it, leave it blank, do not remove it.
--function DrawSubProcessShape(TotalRunning,CurrentDrawingIndex,CurrentActiveWindow)
--	TotalRunning = TotalRunning - 1
--
--	--Distance between dots. Normally they are 6 pixel, if there're too much subprocess and they're possibly overflow icon zone, (IconGap+IconSize)/TotalRunning will be new DotGap.
--	local DotGap = 6
--	if (DotGap * TotalRunning) > (processWidth - IconGap) then
--		DotGap = (processWidth - IconGap)/TotalRunning
--	end
--	--Distance between first dot and last dot
--	local totalDotSpace = TotalRunning * DotGap 
--	if CurrentActiveWindow then 
--		DotTrait = 'ActiveDotColor'
--	else
--		DotTrait = 'DotColor'
--	end
--	--Start drawing
--	for j = 0,TotalRunning do
--		SKIN:Bang('!SetOption SubprocessTrackingShape Shape'..shapeCount..' "Ellipse '..(processWidth/2 + processWidth * CurrentDrawingIndex - totalDotSpace/2 + j*DotGap)..',(#Bar_Height#-3),1.5 | StrokeWidth 0 | Extend '..DotTrait..'"')
--		shapeCount=shapeCount+1
--	end
--end

function DrawSubProcessShape(TotalRunning,CurrentDrawingIndex,CurrentActiveWindow)
	TotalRunning = TotalRunning - 1

	if CurrentActiveWindow then 
		SKIN:Bang('!SetOption SubprocessTrackingShape Shape'..shapeCount..' "Rectangle '..(processWidth * CurrentDrawingIndex)..',#Bar_Height#,'..processWidth..',-0.8 | StrokeWidth 0 | Extend ActiveTrait"')
		shapeCount=shapeCount+1
	end
	
end

--DrawProcessBackground function used for drawing background under all application.
--TotalProcess: total number of processes.
--If theme doesn't need it, leave it blank, do not remove it.
function DrawProcessBackground(TotalProcess)
	SKIN:Bang('!SetOption TaskbarShape Shape2 "Rectangle 0,0,'..(TotalProcess*processWidth)..',#Bar_Height# | StrokeWidth 0 | Fill Color 00000001"')
end

--DrawIconHighlight function used for drawing attribute of icon when mouse is hovering on.
--iconIndex: taskbar index of process mouse currently over.
--If theme doesn't need it, leave it blank, do not remove it.
function DrawIconHighlight(iconIndex)
	SKIN:Bang('!SetOption', iconIndex..'Icon', 'ImageTint', '#Icon_MouseOver_TintColor#')
	SKIN:Bang('!SetOption', iconIndex..'Icon', 'GreyScale', 0)
	SKIN:Bang('!UpdateMeter', iconIndex..'Icon')
	SKIN:Bang('!SetOption', iconIndex..'Shape', 'Trait', 'StrokeWidth 0 | Fill Color #Color_Scheme3#')
	SKIN:Bang('!UpdateMeter', iconIndex..'Shape')
	SKIN:Bang('!Redraw')
end

--ProcessMouseLeave function used for drawing attribute of icon when mouse leaves.
--iconIndex: taskbar index of process that mouse just leaves.
--If theme doesn't need it, leave it blank, do not remove it.
function ProcessMouseLeave(iconIndex)
	SKIN:Bang('!SetOption', iconIndex..'Icon', 'ImageTint', '#Icon_MouseLeave_TintColor#')
	SKIN:Bang('!SetOption', iconIndex..'Icon', 'GreyScale', 1)
	SKIN:Bang('!UpdateMeter', iconIndex..'Icon')
	SKIN:Bang('!SetOption', iconIndex..'Shape', 'Trait', 'StrokeWidth 0 | Fill Color 0,0,0,1')
	SKIN:Bang('!UpdateMeter', iconIndex..'Shape')
	SKIN:Bang('!Redraw')
end