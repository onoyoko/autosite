/*
*	<fieldset><legend>title</legend>
*			<form method="GET"  enctype="text/plain" onsubmit="return formCheck()">
*				<label for="naam">naam</label><input type="text" name="naam" value="Lieven" />
*				<label for="email">email</label><input type="text" name="email"value="info@djdb.be" />
*			<fieldset id="doc">
*			</fieldset>	
*			<input type="submit" value="5" name="submit"/>
*			</form>
*	</fieldset>
*/
var report_id = "doc";
function is_regexpres(string,reg) {
   return reg.test(string)
}
function is_reknr(field){
	with (field) {
		return is_regexpres(field.value,/^\d{3}\-\d{5}\-\d{2}$/);
	}
}
function is_BEreknr(string,contnr){
	var x = 0;
	var y = x+1;
	var result
	for (i=0;i<=10;i++)
	{ if (i!=3){
	    result += string.substring(x,y);
		x++;
		y++;
      }
	}
	return  (result%97+contnr == 0)
	//de som van tien eerste cijfers delen door 97,  twee laatste cijfers 
}
function is_NLreknr(string,contnr){
	var x = 0;
	var y = x+1;
	var result
	for (i=0;i<=8;i++)
	{ if (i!=3){
        result += (string.substring(x,y) * (9 - string.substring(x,y)));
        x++;
		y++;
      }
	}
	return  (result%11+contnr ==0)
}
function is_email(field){
	with (field) {
		return (is_speedmail(field.value)&&is_regemail(field.value));
	}
}
function is_speedmail(string){
		apos = string.indexOf("@");
		dotpos = string.lastIndexOf(".");
		return (apos < 1 || dotpos - apos < 2);
}
function is_regemail (string){		
	return is_regexpres(string,/^[_a-z0-9-]+(\.[_a-z0-9-]+)*@[a-z0-9-]+(\.[a-z0-9-]+)*(\.[a-z]{2,4})$/);
}
function is_date(field){
	with (field) {
		return (is_speeddate(field.value)&& is_regedate(field.value));
	}
}
function is_speeddate(string){
	return (is_regexpres(string,/^\d{2}-d{2}-d{4}$/)||is_regexpres(string,/^\d{2}\/d{2}\/d{4}$/));
	//00-00-0000=>99-99-9999 ||00/00/0000=>99/99/9999 
}
function is_regedate(string){//éénmaal 0=>9 or 00=>29 or 30=>31 - 10=>12 - 0000=>9999
		//test posible delete[0-9]
	return (is_regexpres(string,/^[0-9]|[0,1,2][0-9]|3[0,1]-[\d]|1[0,1,2]-\d{4}$/)||is_regexpres(string,/^[0-9]|[0,1,2][0-9]|3[0,1]\/[\d]|1[0,1,2]\/\d{4}$/));
}
function is_url(field){
	with (field){
		return is_regexpres(field.value,/^(?:(?:ftp|https?):\/\/)?(?:[a-z0-9](?:[-a-z0-9]*[a-z0-9])?\.)+(?:com|edu|biz|org|gov|int|info|mil|net|name|museum|coop|aero|[a-z][a-z])\b(?:\d+)?(?:\/[^;"'<>()\[\]{}\s\x7f-\xff]*(?:[.,?]+[^;"'<>()\[\]{}\s\x7f-\xff]+)*)?/);
	}
}
function is_empty(field){
	with (field){
		return (field.value==null||field.value=="");
	}  
}
function is_EAN(field){
	with (field){
		return false;
	}  
	//underconstruction
	/* code128 (code 128)
* ean8 (ean 8)
* ean13 (ean 13)
* std25 (standard 2 of 5 - industrial 2 of 5)
* int25 (interleaved 2 of 5)
* msi
*/
}
function set_doc(field,comment){
	with (field) {
		var text = document.createElement("p");
		text.innerHTML = field.nodeName;
		text.innerHTML += " " + field.name + comment;
		//docform.elements[i].value
		document.getElementById(report_id).appendChild(text);
		//docform.elment.
	}
}
function reset_doc(field){
	with (field) {
		document.getElementById(report_id).value("xxx");
	}
}
function formCheck(){
	var ok = true;
	var i =0;
	var docform = document.forms[0];
	reset_doc(docform);
	while (docform.elements[i]){
		if (docform.elements[i].name != "submit"&&docform.elements[i].nodeName=="INPUT") {
			if (is_empty(docform.elements[i])) {
				//docform.elements[i].className = 'red';
				docform.elements[i].previousSibling.className = 'invalid';
				ok =  false;
				set_doc(docform.elements[i]," is emty");
			}else{
				formelementcheck(docform.elements[i]);
			}
		}			
		i++;
	}
	//email.focus();
	return false;
}
function formelementcheck(fieldele){
	with(fieldele){
		fieldele.previousSibling.className = 'invalid';//it is not emty
		var name = fieldele.name;
		if((name == "email"||name == "mail" )&& is_email(fieldele)){
			fieldele.previousSibling.className = 'valid';
			ok =  false;
			set_doc(fieldele," not valid email");
		}
		if(name == "reknr" && is_reknr(fieldele)){
			fieldele.previousSibling.className = 'valid';
			ok =  false;
			set_doc(fieldele," not valid rekeningnr");
		}
		if((name == "ean"||name == "ean13" )&& is_EAN(fieldele)){
			fieldele.previousSibling.className = 'valid';
			ok =  false;
			set_doc(fieldele," not valid EAN");
		}
		if((name == "url"||name == "website" )&& is_url(fieldele)){
			fieldele.previousSibling.className = 'valid';
			ok =  false;
			set_doc(fieldele," not valid url / website");
		}
		if((name == "datum"||name == "date" )&& is_date(fieldele)){
			fieldele.previousSibling.className = 'valid';
			ok =  false;
			set_doc(fieldele,"00-00-0000=>99-99-9999 ||00/00/0000=>99/99/9999");
		}
		
	}
}