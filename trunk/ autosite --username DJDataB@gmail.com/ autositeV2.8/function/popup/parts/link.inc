    <script langauge="javascript">
    function getReturn(){
        return=document.getElementById('Protocoltype').value+document.getElementById('url').value;
    }
    </script>
    document.getElementById('returnval').value
    <fieldset>
        <legend>
          <a href="javascript:SwitchTab('tap1','tap2');" class="tablabel">Link</a>
          <a href="javascript:SwitchTab('tap2','tap1');" class="tablabel">more...</a>
         </legend>
               <label for="Protocoltype">type</label>
                   <select id="Protocoltype">
                       <option value="http://" selected="selected">http://</option>
                       <option value="https://">https://</option>
                       <option value="svn://">svn://</option>
                       <option value="ftp://">ftp://</option>
                       <option value="mailto://">mailto://</option>
                       <option value="news://">news://</option>
                       <option value="/">absolut root/</option>
                       <option value="">anders</option>
                   </select>
                   <br />
               <label for="txtUrl">URL</label>
                   <input value="mysite.php" name="txtUrl" id="url"  type="text" />
               <label for="txtUrl">Doel</label><br />
                  <select id="cmbTarget">
                       <option value=""  selected="selected">none;</option>
                       <option value="frame">&lt;frame&gt;</option>
                       <option value="_blank">Nieuw venster (_blank)</option>
                       <option value="_top">Browser venster (_top)</option>
                       <option value="_self">Zelfde venster (_self)</option>
                       <option value="_parent">Ouder venster (_parent)</option>
                   </select>
               <label for="targetname">Naam doelframe</label>
               <input id="targetname" name="targetname" type="text" />
       </fieldset>
