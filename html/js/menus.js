function populateResolutions()
{
	$("#options-video-resolutions>.resolutions").html("");
	$.each(window.getResolutions(), function(key, value)
	{
		$("#options-video-resolutions>.resolutions").append(
			'<div class="col-md-3 col-xs-4"><button class="btn btn-default btn-block" onclick="window.setResolution(' + value[0] + ', ' + value[1] + ')">' + value[0] + ' x ' + value[1] + '</button></div>');
	});
}
function populateGamepads()
{
	$("#options-controls-gamepad ul.dropdown-menu").html("");
	$.each(window.getGamepads(), function(key, value)
	{
		$("#options-controls-gamepad ul.dropdown-menu").append(
			'<li role="presentation"><a role="menuitem" tabindex="-1" href="" onclick="window.setGamepad(' + value[0] + ')">[' + value[0] + '] ' + value[1] + '</a></li>');
	});
}

function setMenu(menu)
{
	$("div.menu:visible").hide("drop", {direction: (Math.floor(Math.random()*2) ? "up" : "down")}, 200, function()
	{
		$("#"+menu).show("slide", {direction: (Math.floor(Math.random()*2) ? "left" : "right")}, 300);
	});
}

$(document).ready(function()
{
	setMenu("main");
});