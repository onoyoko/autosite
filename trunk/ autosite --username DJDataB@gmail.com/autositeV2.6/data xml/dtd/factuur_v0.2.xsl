<?xml version="1.0" encoding="UTF-8" ?>
<xsl:stylesheet version="1.0"
	xmlns:xsl="http://www.w3.org/1999/XSL/Transform" xmlns:fo="http://www.w3.org/1999/XSL/Format"
	xmlns="http://www.w3.org/1999/XSL/Format" xmlns:xs="http://www.w3.org/2001/XMLSchema">
	<!-- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<layout>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> -->
	<xsl:attribute-set name="H1">
		<xsl:attribute name="font-size">18pt</xsl:attribute>
		<xsl:attribute name="space-before">10pt</xsl:attribute>
		<xsl:attribute name="color">blue</xsl:attribute>
		<xsl:attribute name="font-family">Helvetica</xsl:attribute>
		<xsl:attribute name="border">solid</xsl:attribute>
	</xsl:attribute-set>
	<xsl:attribute-set name="H2">
		<xsl:attribute name="font-size">18pt</xsl:attribute>
		<xsl:attribute name="color">black</xsl:attribute>
	</xsl:attribute-set>
	<xsl:attribute-set name="transactionc1">
		<xsl:attribute name="text-align">left</xsl:attribute>
	</xsl:attribute-set>
	<xsl:attribute-set name="transactionc2">
		<xsl:attribute name="text-align">left</xsl:attribute>
	</xsl:attribute-set>
	<xsl:attribute-set name="transactionc3">
		<xsl:attribute name="text-align">right</xsl:attribute>
	</xsl:attribute-set>
	<xsl:attribute-set name="tleft">
		<xsl:attribute name="text-align">left</xsl:attribute>
	</xsl:attribute-set>
	<xsl:attribute-set name="tright">
		<xsl:attribute name="text-align">right</xsl:attribute>
	</xsl:attribute-set>
<!-- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<document start>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> -->
		<xsl:template match="/">
		<fo:root>
			<fo:layout-master-set>
				<fo:simple-page-master master-name="Main" page-height="29.7cm" page-width="21cm" margin-top="1.8cm"	margin-bottom="1cm" margin-left="2cm" margin-right="2cm">
					<fo:region-body />
				</fo:simple-page-master>
			</fo:layout-master-set>
			<fo:page-sequence master-reference="Main">
				<fo:flow flow-name="xsl-region-body">
					<xsl:copy-of select="$header" />
					<xsl:copy-of select="$link" />
<!-- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<iteratie transaction>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> -->
					<xsl:apply-templates select="factuur/items/item" /> 
				</fo:flow>
			</fo:page-sequence>
		</fo:root>
	</xsl:template>
<!-- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<per element transaction>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> -->
	<xsl:template match="factuur/items/item">
		<fo:table table-layout="fixed">
			<fo:table-column column-width="2cm"/>
			<fo:table-column column-width="*"/>
			<fo:table-column column-width="3cm"/>
			<fo:table-body>
				<fo:table-row>
					<fo:table-cell >
						<xsl:element name="fo:block" use-attribute-sets="faclinec1">
							<xsl:value-of select="aantal" />
						</xsl:element>
					</fo:table-cell>
					<fo:table-cell >
						<xsl:element name="fo:block" use-attribute-sets="faclinec2">
							<xsl:value-of select="description" />
									<fo:block linefeed-treatment="preserve"/>
											<xsl:value-of select="stukprijs" />
									<fo:block linefeed-treatment="preserve"/>
						</xsl:element>
					</fo:table-cell>
					<fo:table-cell >
						<xsl:element name="fo:block" use-attribute-sets="faclinec3">
							<xsl:value-of select="linetotal" />
						</xsl:element>
					</fo:table-cell>
				</fo:table-row>
			</fo:table-body>
		</fo:table>
	</xsl:template>

	<!-- <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<fixed blokken>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> -->
	<xsl:variable name="header" >
		<xsl:element name="fo:block" use-attribute-sets="tright">					
			<xsl:apply-templates select="factuur/koper/adres" />
	  </xsl:element>
	</xsl:variable>
	<xsl:template name="factuur/koper/adres">
	 	<fo:block flow-name="region-start">
		 	<xsl:value-of select="naam" />
	        <xsl:value-of select="adres" />
	    </fo:block>
	</xsl:template>
	<xsl:variable name="link">
	</xsl:variable>
</xsl:stylesheet>