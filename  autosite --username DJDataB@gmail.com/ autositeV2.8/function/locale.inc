<?php
class locale{
	private $lang;
	function locale(){
		$thelang = $_SERVER["HTTP_ACCEPT_LANGUAGE"];
		if(strlen($thelang)<3){
			$lang = $thelang;
		}else{
			list($lang, $country)=split("-",$thelang,2);
		}
		$this->lang=$lang;
	}
	function getlang(){
		$langs = array(
		'af' => 'Afrikaans',
		'sq' => 'Albanian',
		'ar' => 'Arabic',
		'hy' => 'Armenian',
		'as' => 'Assamese',
		'az' => 'Azeri',
		'eu' => 'Basque',
		'be' => 'Belarusian',
		'bn' => 'Bengali',
		'bg' => 'Bulgarian',
		'ca' => 'Catalan',
		'zh' => 'Chinese',
		'hr' => 'Croatian',
		'cs' => 'Czech',
		'da' => 'Danish',
		'div' => 'Divehi',
		'nl' => 'Dutch',
		'en' => 'English',
		'us' => 'English',
		'et' => 'Estonian',
		'fo' => 'Faeroese',
		'fa' => 'Farsi',
		'fi' => 'Finnish',
		'fr' => 'French',
		'mk' => 'FYRO Macedonian',
		'gd' => 'Gaelic',
		'ka' => 'Georgian',
		'de' => 'German',
		'el' => 'Greek',
		'gu' => 'Gujarati',
		'he' => 'Hebrew',
		'hi' => 'Hindi',
		'hu' => 'Hungarian',
		'is' => 'Icelandic',
		'id' => 'Indonesian',
		'it' => 'Italian',
		'ja' => 'Japanese',
		'kn' => 'Kannada',
		'kk' => 'Kazakh',
		'kok' => 'Konkani',
		'ko' => 'Korean',
		'kz' => 'Kyrgyz',
		'lv' => 'Latvian',
		'lt' => 'Lithuanian',
		'ms' => 'Malay',
		'ml' => 'Malayalam',
		'mt' => 'Maltese',
		'mr' => 'Marathi',
		'mn' => 'Mongolian',
		'ne' => 'Nepali',
		'no' => 'Norwegian',
		'or' => 'Oriya',
		'pl' => 'Polish',
		'pt' => 'Portuguese',
		'pa' => 'Punjabi',
		'rm' => 'Rhaeto-Romanic',
		'ro' => 'Romanian',
		'ru' => 'Russian',
		'sa' => 'Sanskrit',
		'sr' => 'Serbian',
		'sk' => 'Slovak',
		'ls' => 'Slovenian',
		'sb' => 'Sorbian',
		'es' => 'Spanish',
		'sx' => 'Sutu',
		'sw' => 'Swahili',
		'sv' => 'Swedish',
		'syr' => 'Syriac',
		'ta' => 'Tamil',
		'tt' => 'Tatar',
		'te' => 'Telugu',
		'th' => 'Thai',
		'ts' => 'Tsonga',
		'tn' => 'Tswana',
		'tr' => 'Turkish',
		'uk' => 'Ukrainian',
		'ur' => 'Urdu',
		'uz' => 'Uzbek',
		'vi' => 'Vietnamese',
		'xh' => 'Xhosa',
		'yi' => 'Yiddish',
		'zu' => 'Zulu' );
	}
	function getcountry(){
		$countrys = array(
		'ae' => 'U.A.E.',
		'ar' => 'Argentina',
		'at' => 'Austria',		
		'au' => 'Australia',		
		'be' => 'Belgium',
		'bh' => 'Bahrain',
		'bo' => 'Bolivia',
		'br' => 'Brazil',
		'bz' => 'Belize',	
		'ca' => 'Canada',
		'ch' => 'Switzerland',
		'cl' => 'Chile',
		'co' => 'Colombia',
		'cr' => 'Costa Rica',
		'cn' => 'China',	
		'do' => 'Dominican Republic',
		'dz' => 'Algeria',	
		'ec' => 'Ecuador',
		'eg' => 'Egypt',	
		'fi' => 'Finland',	
		'gb' => 'United Kingdom',
		'gt' => 'Guatemala',
		'hk' => 'Hong Kong SAR',
		'hn' => 'Honduras',	
		'ie' => 'Ireland',
		'iq' => 'Iraq',
		'jm' => 'Jamaica',
		'jo' => 'Jordan',	
		'kw' => 'Kuwait',	
		'lb' => 'Lebanon',
		'li' => 'Liechtenstein',
		'lu' => 'Luxembourg',
		'ly' => 'libya',	
		'ma' => 'Morocco',
		'mc' => 'Monaco',
		'md' => 'Moldova',
		'mo' => 'Macau SAR',
		'mx' => 'Mexico',
		'ni' => 'Nicaragua',
		'no' => 'Bokmal',
		'no' => 'Nynorsk',
		'nz' => 'New Zealand',	
		'om' => 'Oman',
		'pa' => 'Panama',
		'pe' => 'Peru',
		'ph' => 'Philippines',
		'pr' => 'Puerto Rico',
		'py' => 'Paraguay',
		'qa' => 'Qatar',
		'sa' => 'Saudi Arabia',	
		'sg' => 'Singapore',
		'sy' => 'Syria',
		'sv' => 'El Salvador',
		'tn' => 'Tunisia',
		'tt' => 'Trinidad',	
		'tw' => 'Taiwan',
		'us' => 'United States',
		'uy' => 'Uruguay',
		've' => 'Venezuela',
		'ye' => 'Yemen',
		'za' => 'South Africa',
		'zw' => 'Zimbabwe');
	}
	function getuserlocale(){
		print $this->lang;
	}
	/*
		$languages =str_replace( ' ', '', $languages );
		$languages =explode( ",", $languages );
		foreach($languages as $language_list){
			$temp_array = array();
			$temp_array[0] = substr($language_list, 0, strcspn( $language_list, ';' ) );//full language
			$temp_array[1] = substr( $language_list, 0, 2 );// cut out primary language
			$user_languages[] = $temp_array;
		}
		for( $i = 0; $i < count( $user_languages ); $i++ ){
			foreach( $a_languages as $index => $complete ){
				if( $index == $user_languages[$i][0] ){
					// complete language, like english (canada)
					$user_languages[$i][2] = $complete;
					// extract working language, like english
					$user_languages[$i][3] = substr( $complete, 0, strcspn( $complete, ' (' ) );
				}
			}
		}
	*/
}
?>