
		function fotoOK() {//foto ok?
			if (document.images)	return true;
			else return false;
		}
		function laadfoto(fotoURL) {
			if (BrowserOK) {
				if (document.all){
					document.images.fotoshow.style.filter="blendTrans(duration=2)";
					document.images.fotoshow.style.filter="blendTrans(duration=fadetijd)";
					document.images.fotoshow.filters.blendTrans.Apply();
				}
				document.fotoshow.src = fotoURL;
				if (document.all){
					document.images.fotoshow.filters.blendTrans.Play();
				}
				return false;
			}
			else {
				return true;
			}}
		function volgendefoto() {
			gekozenfoto = (gekozenfoto + 1) % aantalfotos;
			laadfoto(fotos[gekozenfoto]);
		}
		BrowserOK = fotoOK();
		gekozenfoto = 0;
		setInterval("volgendefoto()",intervaltijd * 1000);