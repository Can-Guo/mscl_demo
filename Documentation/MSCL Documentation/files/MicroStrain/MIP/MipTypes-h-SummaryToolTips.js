NDSummary.OnToolTipsLoaded("File:MicroStrain/MIP/MipTypes.h",{2902:"<div class=\"NDToolTip TStruct LC\"><div class=\"TTSummary\">Contains enumeration/types for various MIP information</div></div>",2904:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">The enums for all the different data classes of MIP data.</div></div>",2915:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">The enums for all the different types/categories of MIP commands and data.</div></div>",2922:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">The enums for enable or disable of data.</div></div>",2925:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">The enums to represent different time categories.</div></div>",2928:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">The enums for all of the different MIP commands.</div></div>",3047:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">The enums for all of the different MIP Channel Field IDs.</div></div>",3301:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">The enums for different MIP Channel Qualifiers.&nbsp; This combined with the ChannelField produces a unique identifier for each individual channel that is collected.</div></div>",3401:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A typedef for a ChannelField, ChannelQualifier pair.</div></div>",3403:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3403\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> DataClass channelFieldToDataClass(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\">MipTypes::</td><td class=\"PType\">ChannelField&nbsp;</td><td class=\"PName last\">channelField</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gets the DataClass for a MipTypes::ChannelField.</div></div>",3404:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3404\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> std::<span class=\"SHKeyword\">string</span> channelName(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">ChannelField&nbsp;</td><td class=\"PName last\">field,</td></tr><tr><td class=\"PType first\">ChannelQualifier&nbsp;</td><td class=\"PName last\">qualifier</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gets the name of the specified ChannelId.&nbsp; This is the universal channel name that should be used for uploading to SensorCloud.</div></div>",3405:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3405\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> MipChannelFields getChannelFields_allDataClasses(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">ChannelField&nbsp;</td><td class=\"PName last\">chField</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Get a list of ChannelFields representing the same descriptor/channel field across all GNSS data classes</div></div>",3406:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3406\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> ChannelField getChannelField_baseDataClass(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">ChannelField&nbsp;</td><td class=\"PName last\">chField</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gets the ChannelField representing the provided channel field\'s equivalent in the original GNSS data class (0x81)</div></div>",3407:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3407\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> ChannelField getChannelField_toDataClass(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">ChannelField&nbsp;</td><td class=\"PName last\">chField,</td></tr><tr><td class=\"PType first\">DataClass&nbsp;</td><td class=\"PName last\">dataClass</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gets the ChannelField representing the provided channel field\'s equivalent in the specified DataClass</div></div>",3408:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3408\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> std::<span class=\"SHKeyword\">string</span> getChannelNamePrependText(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">ChannelField&nbsp;</td><td class=\"PName last\">chField</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gets the text to prepend the channel name to distinguish between different GNSS data classes</div></div>",3409:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3409\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static</span> std::<span class=\"SHKeyword\">string</span> getChannelNameAppendText(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">ChannelField&nbsp;</td><td class=\"PName last\">chField</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Gets the text to append to the channel name to distinguish between different shared data fields</div></div>",3410:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3410\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static bool</span> isGnssChannelField(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">ChannelField&nbsp;</td><td class=\"PName last\">chField</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Checks whether the provided ChannelField is within a GNSS data set.</div></div>",3411:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3411\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">static bool</span> isSharedChannelField(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">ChannelField&nbsp;</td><td class=\"PName last\">chField</td></tr></table></td><td class=\"PAfterParameters\">)</td></tr></table></div><div class=\"TTSummary\">Checks whether the provided ChannelField is a shared field amongst all inertial data sets.</div></div>",3413:"<div class=\"NDToolTip TConstant LC\"><div class=\"TTSummary\">An unordered_map mapping each ChannelId to its respective name (universal SensorCloud name).</div></div>",3415:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3415\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">static</span> std::vector&lt;DataClass&gt; GNSS_DATA_CLASSES()</div><div class=\"TTSummary\">vector of DataClass values containing all GNSS data class descriptors that have the same field descriptors.&nbsp; was a const but ran into static initialization order issues with registering GNSS field parsers.</div></div>",3416:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3416\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">static</span> std::vector&lt;DataClass&gt; INERTIAL_DATA_CLASSES()</div><div class=\"TTSummary\">vector of DataClass values containing all inertial data class descriptors that have the same field descriptors.&nbsp; was a const but ran into static initialization order issues with registering shared field parsers.</div></div>",3417:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3417\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">static</span> std::vector&lt;<span class=\"SHKeyword\">uint8</span>&gt; SHARED_DATA_FIELDS()</div><div class=\"TTSummary\">vector of uint8 values containing all shared inertial data field descriptors.&nbsp; was a const but ran into static initialization order issues with registering shared field parsers.</div></div>",3418:"<div class=\"NDToolTip TClass LC\"><div class=\"NDClassPrototype\" id=\"NDClassPrototype3418\"><div class=\"CPEntry TClass Current\"><div class=\"CPName\">MipChannelIdentifier</div></div></div><div class=\"TTSummary\">A single additional identifier for a MipDataPoint. Contains a uint value with an identifier type specifier.</div></div>",3428:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">ID definitions when Type is &lt;MipChannelIdentifier::Type::AIDING_MEASUREMENT_TYPE&gt; GNSS&nbsp; - 0x01 - GNSS DUAL_ANTENNA&nbsp; - 0x02 - Dual Antenna HEADING&nbsp; - 0x03 - Heading PRESSURE&nbsp; - 0x04 - Pressure MAGNETOMETER&nbsp; - 0x05 - Magnetometer SPEED&nbsp; - 0x06 - Speed</div></div>",3429:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">ID definitions when Type is &lt;MipChannelIdentifier::Type::GNSS_CONSTELLATION&gt; UNKNOWN_CONSTELLATION - 0 - Unknown GPS&nbsp; - 1 - GPS GLONASS&nbsp; - 2 - GLONASS GALILEO&nbsp; - 3 - Galileo BEIDOU&nbsp; - 4 - BeiDou</div></div>",3430:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">ID definitions when Type is &lt;MipChannelIdentifier::Type::GNSS_SIGNAL_ID&gt; UNKNOWN&nbsp; - 0 GPS_L1CA&nbsp; - 1 GPS_L1P&nbsp; - 2 GPS_L1Z&nbsp; - 3 GPS_L2CA&nbsp; - 4 GPS_L2P&nbsp; - 5 GPS_L2Z&nbsp; - 6 GPS_L2CL&nbsp; - 7 GPS_L2CM&nbsp; - 8 GPS_L2CML&nbsp; - 9 GPS_L5I&nbsp; - 10 GPS_L5Q&nbsp; - 11 GPS_L5IQ&nbsp; - 12 GPS_L1CD&nbsp; - 13 GPS_L1CP&nbsp; - 14 GPS_L1CDP&nbsp; - 15 GLONASS_G1CA&nbsp; - 32 GLONASS_G1P&nbsp; - 33 GLONASS_G2C&nbsp; - 34 GLONASS_G2P&nbsp; - 35 GALILEO_E1C&nbsp; - 64 GALILEO_E1A&nbsp; - 65 GALILEO_E1B&nbsp; - 66 GALILEO_E1BC&nbsp; - 67 GALILEO_E1ABC&nbsp; - 68 GALILEO_E6C&nbsp; - 69 GALILEO_E6A&nbsp; - 70 GALILEO_E6B&nbsp; - 71 GALILEO_E6BC&nbsp; - 72 GALILEO_E6ABC&nbsp; - 73 GALILEO_E5BI&nbsp; - 74 GALILEO_E5BQ&nbsp; - 75 GALILEO_E5BIQ&nbsp; - 76 GALILEO_E5ABI&nbsp; - 77 GALILEO_E5ABQ&nbsp; - 78 GALILEO_E5ABIQ&nbsp; - 79 GALILEO_E5AI&nbsp; - 80 GALILEO_E5AQ&nbsp; - 81 GALILEO_E5AIQ&nbsp; - 82 SBAS_L1CA&nbsp; - 96 SBAS_L5I&nbsp; - 97 SBAS_L5Q&nbsp; - 98 SBAS_L5IQ&nbsp; - 99 QZSS_L1CA&nbsp; - 128 QZSS_LEXS&nbsp; - 129 QZSS_LEXL&nbsp; - 130 QZSS_LEXSL&nbsp; - 131 QZSS_L2CM&nbsp; - 132 QZSS_L2CL&nbsp; - 133 QZSS_L2CML&nbsp; - 134 QZSS_L5I&nbsp; - 135 QZSS_L5Q&nbsp; - 136 QZSS_L5IQ&nbsp; - 137 QZSS_L1CD&nbsp; - 138 QZSS_L1CP&nbsp; - 139 QZSS_L1CDP&nbsp; - 140 BEIDOU_B1I&nbsp; - 160 BEIDOU_B1Q&nbsp; - 161 BEIDOU_B1IQ&nbsp; - 162 BEIDOU_B3I&nbsp; - 163 BEIDOU_B3Q&nbsp; - 164 BEIDOU_B3IQ&nbsp; - 165 BEIDOU_B2I&nbsp; - 166 BEIDOU_B2Q&nbsp; - 167 BEIDOU_B2IQ&nbsp; - 168</div></div>",3431:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A typedef for a MipChannelIdentifier::Type, uint32 pair.</div></div>",3433:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3433\" class=\"NDPrototype NoParameterForm\">MipChannelIdentifier()</div><div class=\"TTSummary\">Default constructor</div></div>",3434:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3434\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">MipChannelIdentifier(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Type&nbsp;</td><td class=\"PName last\">identiferType,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">uint32</span>&nbsp;</td><td class=\"PName last\">id</td></tr></table></td><td class=\"PAfterParameters\">) : m_type(identiferType), m_id(id)</td></tr></table></div><div class=\"TTSummary\">Construct MipChannelIdentifier object with specified MipChannelIdentifier::Type and ID values.</div></div>",3435:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3435\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">MipChannelIdentifier(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Type&nbsp;</td><td class=\"PName last\">identiferType,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">uint32</span>&nbsp;</td><td class=\"PName last\">id,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">uint32</span>&nbsp;</td><td class=\"PName last\">specifier</td></tr></table></td><td class=\"PAfterParameters\">) : m_type(identiferType), m_id(id), m_specifier(specifier)</td></tr></table></div><div class=\"TTSummary\">Construct MipChannelIdentifier object with specified MipChannelIdentifier::Type and ID values.</div></div>",3436:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3436\" class=\"NDPrototype NoParameterForm\">Type identifierType() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Returns the MipChannelIdentifier::Type specifier of this identifier.</div></div>",3437:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3437\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">uint32</span> id() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Returns the identifier value.</div></div>",3438:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3438\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">bool</span> hasSpecifier() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Indicates whether this identifier has an optional additional specifier.</div></div>",3439:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3439\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">uint32</span> specifier() <span class=\"SHKeyword\">const</span></div><div class=\"TTSummary\">Returns the optional additional specifier value.&nbsp; Note: this is only valid and applicable if hasSpecifier returns true - value may be non-zero regardless.</div></div>",3440:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3440\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">std::<span class=\"SHKeyword\">string</span> name(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\"><span class=\"SHKeyword\">bool</span>&nbsp;</td><td class=\"PName\">standardizedFormat&nbsp;</td><td class=\"PDefaultValueSeparator\">=&nbsp;</td><td class=\"PDefaultValue last\"><span class=\"SHKeyword\">true</span></td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">const</span></td></tr></table></div><div class=\"TTSummary\">Returns the string representation of this identifier based on type and value.</div></div>",3442:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype3442\" class=\"NDPrototype NoParameterForm\">Type m_type</div><div class=\"TTSummary\">The MipChannelIdentifier::Type indicator of this identifier.</div></div>",3443:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype3443\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">uint32</span> m_id</div><div class=\"TTSummary\">The value of this identifier.</div></div>",3444:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype3444\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">uint32</span> m_specifier</div><div class=\"TTSummary\">An option additional specifier for this identifier.</div></div>",3446:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3446\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\"><span class=\"SHKeyword\">bool</span> hasSpecifier(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PModifierQualifier first\">std::</td><td class=\"PType\"><span class=\"SHKeyword\">string</span>&nbsp;</td><td class=\"PNamePrefix\">&amp;</td><td class=\"PName last\">specifierName</td></tr></table></td><td class=\"PAfterParameters\">) <span class=\"SHKeyword\">const</span></td></tr></table></div><div class=\"TTSummary\">Indicates whether this identifier has an optional additional specifier.&nbsp; Parameters: specifierName - string reference that is set to the specifier name if found</div></div>",3448:"<div class=\"NDToolTip TConstant LC\"><div class=\"TTSummary\">A map of MipChannelIdentifier::Type values and their string labels.</div></div>",3449:"<div class=\"NDToolTip TConstant LC\"><div class=\"TTSummary\">A map of MipChannelIdentifier::TypeId values and their string labels.</div></div>",3450:"<div class=\"NDToolTip TConstant LC\"><div class=\"TTSummary\">A map of &lt;MipChannelIdentifier::SpecifierId&gt; values and their string labels.</div></div>",3452:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A vector of MipChannelIdentifier values, used to assign additional identifiers to a MipDataPoint</div></div>",3453:"<div class=\"NDToolTip TStruct LC\"><div class=\"TTSummary\">Contains an &lt;Command&gt; id and a BytesCollection vector to store the actual bytes to send to the device for that command.</div></div>",3455:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A vector of MipCommandBytes</div></div>",3456:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A ValueType vector</div></div>",3457:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A Value vector</div></div>",3458:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A list of &lt;MipCommandParameterList&gt; command/parameter definitions</div></div>",3459:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A MipTypes::FunctionSelector vector</div></div>",3460:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A map of locations and values to match in a MIP response to determine success</div></div>",3461:"<div class=\"NDToolTip TStruct LC\"><div class=\"TTSummary\">Maps GNSS Receiver ID to the MipTypes::DataClass it outputs to</div></div>",3463:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3463\" class=\"NDPrototype NoParameterForm\">GnssReceiverInfo()</div><div class=\"TTSummary\">Constructs GnssReceiverInfo object with default values</div></div>",3464:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3464\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">GnssReceiverInfo(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"first\"></td><td class=\"PType\"><span class=\"SHKeyword\">uint8</span>&nbsp;</td><td class=\"PName last\">recId,</td></tr><tr><td class=\"PModifierQualifier first\">MipTypes::</td><td class=\"PType\">DataClass&nbsp;</td><td class=\"PName last\">target,</td></tr><tr><td class=\"PModifierQualifier first\">std::</td><td class=\"PType\"><span class=\"SHKeyword\">string</span>&nbsp;</td><td class=\"PName last\">desc</td></tr></table></td><td class=\"PAfterParameters\">) : id(recId), targetDataClass(target), description(desc)</td></tr></table></div><div class=\"TTSummary\">Constructs GnssReceiverInfo object with specified values</div></div>",3466:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype3466\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">uint8</span> id</div><div class=\"TTSummary\">Receiver ID</div></div>",3467:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype3467\" class=\"NDPrototype NoParameterForm\">MipTypes::DataClass targetDataClass</div><div class=\"TTSummary\">MIP data class associated with this receiver</div></div>",3468:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype3468\" class=\"NDPrototype NoParameterForm\">std::<span class=\"SHKeyword\">string</span> description</div><div class=\"TTSummary\">ASCII description of receiver</div></div>",3470:"<div class=\"NDToolTip TType LC\"><div class=\"TTSummary\">A vector of GnssReceiverInfo</div></div>",3471:"<div class=\"NDToolTip TStruct LC\"><div class=\"TTSummary\">Stores info related to device comm ports (id, type)</div></div>",3473:"<div class=\"NDToolTip TEnumeration LC\"><div class=\"TTSummary\">Available comm port type definitions PRIMARY - 0 AUX&nbsp; - 1</div></div>",3475:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3475\" class=\"NDPrototype NoParameterForm\">DeviceCommPort()</div><div class=\"TTSummary\">Constructs DeviceCommPort object with default values</div></div>",3476:"<div class=\"NDToolTip TFunction LC\"><div id=\"NDPrototype3476\" class=\"NDPrototype WideForm CStyle\"><table><tr><td class=\"PBeforeParameters\">DeviceCommPort(</td><td class=\"PParametersParentCell\"><table class=\"PParameters\"><tr><td class=\"PType first\">Type&nbsp;</td><td class=\"PName last\">portType,</td></tr><tr><td class=\"PType first\"><span class=\"SHKeyword\">uint8</span>&nbsp;</td><td class=\"PName last\">portId</td></tr></table></td><td class=\"PAfterParameters\">) : type(portType), id(portId)</td></tr></table></div><div class=\"TTSummary\">Constructs DeviceCommPort object with specified values</div></div>",3478:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype3478\" class=\"NDPrototype NoParameterForm\">Type type</div><div class=\"TTSummary\">Port type (primary, aux, etc.)</div></div>",3479:"<div class=\"NDToolTip TVariable LC\"><div id=\"NDPrototype3479\" class=\"NDPrototype NoParameterForm\"><span class=\"SHKeyword\">uint8</span> id</div><div class=\"TTSummary\">Port ID</div></div>"});