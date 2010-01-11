var myPopup = window.createPopup();
function PopUp(textMessage){
	// EXAMPLE :: onmouseover="PopUp('Some Message');" onmouseout="myPopup.hide();"
	var myPopBody = myPopup.document.body;
	var myPopupDiv = document.createElement('DIV');
	var myPopupWidth = 0;
	var myPopupHeight; = 0;
	var myPopupOffSet = 20;
	var myPopupXBuffer = 4;
	var myPopupYBuffer = 4;
	var modifiedtextMessage = new String(textMessage).replace(/ /gi,'&nbsp ;');
	// Set Up Da' Pop Up
	with(myPopBody){
		//General Appearance
		style.textAlign = 'center';
		style.verticalAlign = 'middle';
		style.backgroundColor = 'lightyellow';
		style.border = 'solid black 1px';
		// Font Settings
		style.fontFamily = 'Arial';
		style.fontWeight = 500;
		style.fontStyle = 'normal';
		style.fontSize = '8pt';
		style.color = '#004080';
	}
	//Determine Actual Width
	with(myPopupDiv){
		id = 'myPopupDiv';
		style.position = 'absolute';
		style.visibility = 'hidden';
		style.fontFamily = myPopBody.style.fontFamily;
		style.fontWeight = myPopBody.style.fontWeight;
		style.fontSize = myPopBody.style.fontSize;
		style.fontStyle = myPopBody.style.fontStyle;
		innerHTML = modifiedtextMessage;
	}
	this.document.body.appendChild(myPopupDiv);
	// Display Da' Pop Up
	myPopupWidth = (myPopupDiv.clientWidth + myPopupXBuffer)
	myPopupHeight = (myPopupDiv.clientHeight + myPopupYBuffer);
	myPopBody.innerHTML = modifiedtextMessage;
	myPopup.show((window.event.x + myPopupOffSet), window.event.y, myPopupWidth, myPopupHeight, this.document.body);
}
