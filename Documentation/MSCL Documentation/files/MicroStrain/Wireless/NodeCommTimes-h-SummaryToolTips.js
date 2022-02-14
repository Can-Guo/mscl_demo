NDSummary.OnToolTipsLoaded("File:MicroStrain/Wireless/NodeCommTimes.h",{7765:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype7765\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">NodeCommTimes</div></div></div><div class=\"TTSummary\">Contains a global map of Wireless Node addresses to last communication times.</div></div>",7767:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype7767\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">static</span> std::map&lt;NodeAddress, Timestamp&gt; m_nodesLastCommTime</div><div class=\"TTSummary\">A map of node address to Timestamp objects, holding the last communication time for nodes.</div></div>",7768:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype7768\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">static</span> std::map&lt;NodeAddress, DeviceState&gt; m_nodesLastState</div><div class=\"TTSummary\">A mpa of node address to DeviceState objects, holding the last known state for nodes.</div></div>",7770:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype7770\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static void</span> updateCommTime(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">NodeAddress&nbsp;</td><td class=\"PName last\">nodeAddress</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Sets the communication time for the given node address to the current system time.</div></div>",7771:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype7771\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static void</span> updateDeviceState(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">NodeAddress&nbsp;</td><td class=\"PName last\">nodeAddress,</td></tr><tr><td class=\"PType first\">DeviceState&nbsp;</td><td class=\"PName last\">state</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Sets the DeviceState for the given node address.</div></div>",7772:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype7772\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static const</span> Timestamp&amp; getLastCommTime(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">NodeAddress&nbsp;</td><td class=\"PName last\">nodeAddress</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gets the last communication time for the given node address.</div></div>",7773:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype7773\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> DeviceState getLastDeviceState(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">NodeAddress&nbsp;</td><td class=\"PName last\">nodeAddress</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gets the last device state for the given node address.</div></div>"});