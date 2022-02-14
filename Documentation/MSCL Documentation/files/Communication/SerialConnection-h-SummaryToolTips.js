NDSummary.OnToolTipsLoaded("File:Communication/SerialConnection.h",{9:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype9\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">SerialConnection</div></div></div><div class=\"TTSummary\">A Connection_Impl derived class that represents a serial connection.</div></div>",11:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype11\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">explicit</span> SerialConnection(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\"><span class=\"SHKeyword\">const</span> std::</td><td class=\"PType\"><span class=\"SHKeyword\">string</span>&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">port,</td></tr><tr><td class=\"first\"></td><td class=\"PType\"><span class=\"SHKeyword\">uint32</span>&nbsp;</td><td></td><td class=\"PName last\">baudRate</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Initializes the SerialConnection object.</div></div>",12:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype12\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">virtual</span> ~SerialConnection()</div><div class=\"TTSummary\">Destroys the SerialConnection object</div></div>",14:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype14\" class=\"NDPrototype NoParameterForm\">std::<span class=\"SHKeyword\">string</span> m_port</div><div class=\"TTSummary\">The string name of the port (ex. &quot;COM26&quot;)</div></div>",15:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype15\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">uint32</span> m_baudRate</div><div class=\"TTSummary\">The baud rate of the connection</div></div>",17:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype17\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">virtual</span> std::<span class=\"SHKeyword\">string</span> description()</div><div class=\"TTSummary\">Gets a description of the connection as a string</div></div>",18:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype18\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">void</span> updateBaudRate(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">uint32</span>&nbsp;</td><td class=\"PName last\">baudRate</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">override</span></td></tr></table></div><div class=\"TTSummary\">Updates the serial connection baud rate.&nbsp; Important: The connection to the port will be closed and re-opened at the new baud rate.</div></div>",19:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype19\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">virtual void</span> establishConnection()</div><div class=\"TTSummary\">Initializes and opens the current connection</div></div>"});