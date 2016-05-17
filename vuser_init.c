/* -------------------------------------------------------------------------------
	Script Title       : 
	Script Description : 
                        
                        
	Recorder Version   : 1203
   ------------------------------------------------------------------------------- */

vuser_init()
{

	lr_start_transaction("Homepage");

	web_reg_find("Text=Example Domain", 
		LAST);

	web_url("www.example.com", 
		"URL=http://www.example.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_set_sockets_option("SSL_VERSION", "2&3");

	/* Request with GET method to URL "http://www.example.com/favicon.ico" failed during recording. Server response : 404*/

	lr_end_transaction("Homepage",LR_AUTO);

	lr_start_transaction("More Info");

	web_reg_find("Text=IANA — IANA-managed Reserved Domains", 
		LAST);

	web_url("More information...", 
		"URL=http://www.iana.org/domains/example", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://www.example.com/", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		EXTRARES, 
		"Url=../_img/2015.1/fonts/NotoSans-Regular.woff", "Referer=http://www.iana.org/domains/reserved", ENDITEM, 
		"Url=../_img/2015.1/fonts/NotoSans-Bold.woff", "Referer=http://www.iana.org/domains/reserved", ENDITEM, 
		"Url=../_img/2015.1/fonts/NotoSans-Italic.woff", "Referer=http://www.iana.org/domains/reserved", ENDITEM, 
		"Url=../_img/2015.1/fonts/SourceCodePro-Regular.woff", "Referer=http://www.iana.org/domains/reserved", ENDITEM, 
		"Url=https://r20swj13mr.microsoft.com/ieblocklist/v1/urlblockindex.bin", "Referer=", ENDITEM, 
		"Url=https://r20swj13mr.microsoft.com/ieblocklist/v1/urlblocklist.bin", "Referer=", ENDITEM, 
		LAST);

	lr_end_transaction("More Info",LR_AUTO);

	return 0;
}