
function setAsHome(myLink){
 try {
    myLink.style.behavior='url(#default#homepage)';
    myLink.setHomePage(location.href);
 }catch(e){
    var msg = "";
    var browserNaam = navigator.appName;
if ( browserNaam == "Netscape" ) {
    msg = "Sleep deze link naar het homepage ";
    msg += "icoontje (het huisje) om deze pagina in te stellen als";
    msg += "startpagina!";
}else if ( browserNaam == "Opera" ) {
    msg = "=> Tools/Extra<br> => Preferences/Voorkeuren <br>  =>Home Page = this url";
   
}else if ( browserNaam == "Microsoft Internet Explorer" ) {
    msg = "=> Tools/Extra<br> => Internet-options/Internet-opties <br> =>Home Page = this url";
}else {
    msg = "ik weet niet welke browser dit is...";
}
alert(msg);
}
} 