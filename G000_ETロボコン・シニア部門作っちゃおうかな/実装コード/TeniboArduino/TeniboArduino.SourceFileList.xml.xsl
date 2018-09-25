<?xml version="1.0" encoding="utf-8"?>
<!--
このファイルは製品(TopLevel)が利用した部品の一覧ファイルを生成します。
Makefileにincludeして利用した部品のみコンパイル対象にするときに利用します。
一覧ファイル名は、このテンプレートファイルの拡張子を削除した名前になります。
カスタマイズは下記★☆の部分を読んで変更してください。
-->
<xsl:stylesheet version="1.0" xmlns:xsl="http://www.w3.org/1999/XSL/Transform">
  <xsl:output method="xml" encoding="utf-8" indent="yes"/>
  <xsl:param name="ID"/>
  <xsl:param name="GeneratorName"/>
  <xsl:param name="GeneratorVersion"/>
  <xsl:param name="CopyrightDate"/>
  <xsl:param name="Trademark"/>
  <xsl:param name="fileSystemSeparator"/>

  <xsl:template match="/">
    <xsl:apply-templates select="InterimDs/GenerateFiles[ID=$ID]"/>
  </xsl:template>

  <xsl:template match="GenerateFiles">
    <xsl:message>Generating UseBlock</xsl:message>
    <SourceFileList>
      <xsl:apply-templates select="UsedBlocks" mode="UsedBlocks"/>
    </SourceFileList>
  </xsl:template>

  <!--
★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆★☆
利用した部品リストを出力します
-->
  <xsl:template match="UsedBlocks" mode="UsedBlocks">
    <Source>
      <xsl:text>..</xsl:text>
      <xsl:value-of select="translate(path, '/', '\')"/>
      <xsl:text>.cpp</xsl:text>
    </Source>
  </xsl:template>

</xsl:stylesheet>
