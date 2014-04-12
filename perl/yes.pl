#!/usr/bin/env perl 
use warnings;
use utf8;
use feature qw/state say switch/;
use List::MoreUtils qw/ uniq /;
my $text = <STDIN>;
my $n = <STDIN>;

@places = qw/
Philipsburg Ponta Delgada PRAIA Jebel Dhanna Khor Fakkan Mina Daqr Ambrizete Benguela Cabinda Lobito Bahia Blanca San Lorenzo Nicolas Pedro Sebastian Bay Santa Cruz Fe Ushuaia Villa Constitucion Zarate Cape Lambert Carnarvon Zeebrugge BG Bulgaria Balchik Bourgas Santos CK Cook Islands Arutunga Rarotonga Island CL Chile Ancud Antofagasta Arica Cabo Negro Caldera Calderilla Caleta Clarencia Patillos Castro Chacabuco Chanaral Coquimbo Coronel Corral Grande Easter Gregorio Guayacan Huasco Iquique La Serena Lirquen Lota Meijilones Penco Puerto Bories Montt Natales Quellon Quemchi Punta Arenas Quintero Antonio Vicente Talcahuano Taltal Tocopilla Tome valdivia Valparaiso CM Cameroon Douala Kribi Tiko Victoria CO Colombia Barranquilla Buenaventura Cartagena Covenas Pozos Colorados Rio Hacha Marta Tumaco CR Costa Rica Golfito Port Limon Puntarenas Quepos CU Cuba Antilla Honda Banes Baracoa Boca Boqueron Cabanas Caibarien Caimanera Cardenas Casilda Ceiba Hueca Cienfuegos Felton Guayabal Havana Isabela Jucaro Manati Manopla Manzanillo Mariel Matanzas Media Luna Moa Nicaro Niquero Nueva Gerona Nuevitas Palo Alto Pastelillo Pilon Preston Padre Tarafa Saguala del Sur Lucia Santiago Tanamo Tunas de Zaza Vita CV Verde Palmeira Porto Praia CY Cyprus Akrotiri Dikhelia Famagusta Karavostassi Kyrenia Larnaca Latchi Limassol Moni Anchorage Morphou Paphos Vassiliko DD German Democratic Reupublic Rostock Stralsund Warnemunde Wismar DE Federal Republic of Germany Altona Bonn Brake Bremen Bremerhaven Bunsbuttel Butzfleth Coblenz Cologne Cuxhaven Duisburg Dusseldorf Eckernforde Elsfleth Emden Flensburg Frankfurt Gluckstadt Hamburg Heiligenhafen Holtenau Husum Itzehoe Kappeln Kiel Krefeld Labo Leer Lubeck Ludwigshafen Mainz Mannheim Neuhaus Neuss Neustadt Nordenham Orth Papenburg Rendsburg Schulau Shcwarzenhutten Stade Stadersand Tonning Travemunde Vegesack Wilhelmsburg Wilhelmshaven DJ Djibouti DK Denmark Aabenraa Aalborg Aarhus Aeroskobing Allinge Assens Bandholm Bogense Copenhagen Ebeltoft Elsinore Esbjerg Faaborg Fakse Ladeplads Fredericia Frederikshavn Frederikssund Frederiksvark Grasten Grenaa Gulfhavn Haderslev Hadsund Hasle Hirtshals Hobro Holbaek Horsens Kalundborg Karrebaeksminde Kerteminde Koge Kolding Korsor Kyndby Lemvig Lyngs Oddde Mariager Marstal Masnedsund Middelfart Naestved Nakskov Nekso Norresundby Nyborg Nykobing Odense Orehoved Randers Rodbyhavn Rodvig Ronne Rudkobing Sakskobing Skaelskor Skaerbaek Skagen Skive Sonderborg Stege Struer Stubbekobing Stvaneke Svendborg Tisted Tuborg Havn Vejle Vordingborg DM Dominica Portsmouth Roseau DO Dominican Azua Barahona China Rojo Romana Palenque Plata Haina Samana Macoris Sanchez Santo Domingo DZ Algeria Annaba Arziw Bejaia Benisaf Cherchell Collo Dellys El Djazair Ghazawet Jijel Mestghanem Skikda Tenes Wahran EC Ecuador Caraguez Balao Terminal Esmeraldas Guayaquil Libertad Manta Bolivar Salinas EG Egypt Abu Zenima Adabiya Ain Sukhna Alexandria Damietta Kosseir Mersa Hamra Matruh Ibrahim Said Tewfik Ras Gharib Shukheir Safaga Salum Sidi Kerir Suez Wadi Feiran EH Western Sahara Dakhla Laayoune ES Spain Adra Aguilas Alcudia Algeciras Alicante Almeria Aviles Barcelona Bilbao Blanes Burela Burriana Cadiz Finistrerre Castellon Urdiales Cilero Corcubion Corunna Denia Escombreras Harbour Ferrol Gandia Garrucha Gijon Huelva Ibiza Javea Calera Luarca Mahon Malaga Marin Mazarron Motril Muros Palamos Palma Pasajes Portugalete Saltacaballo Ribadeo Ribadesella Rosas Rota Sagunto Carlos Ciprian Esteban Pravia Feliu Guixols Fernando Santander Seville Soller Tarragona Torrevieja Valencia Vigo Villagarcia Vivero ET Ethiopia Assab Massawa FI Finland Barosund Degerby Hamina Hanko Helsinki Inkoo Isnas Kaskinen Kemi Kokkola Kotka Koverhar Kristiina Lapaluoto Loviisa Mantyluoto Mariehamn Merikarvia Naantali Nystad Oulu Pargas Pateniemi Pietarsaari Pori Porkkala Porvoo Raahe Rauma Reposaari Saimaa Canal Skuru Tammisaari Toikis Toppila Tornio Turku Uusikaupunki Vaasa Vaskiluoto Veitsiluoto Walkom Ykspihlaja FJ Fiji Ellington Lambasa Lautoka Levuka Savusavu Suva Vatia Point FK Falkland Stanley FO Faeroe Klaksvig Thorshavn Trangisvaag Tvoroyri Vaag Vestmanhavn FR France Abbeville Ajaccio Antibes Antifer Arcachon Bassens Bastia Bayonne Bec Ambes Blaye Bonifacio Bordeaux Boulogne Brest Caen Calais Calvi Cammaret Cancale Cannes Caronte Cherbourg Concarneau Dahouet Deauville Dieppe Donges Douamenez Dunkirk Etaples Fecamp Fos Gonfreville Granville Gravelines Havre Honfleur Ile Rousse Ciotat Nouvelle Pallice Rochelle Landerneau Lavera Le Chateau Guido Libourne Loctudy Lorient Marans Marseilles Martigues Montoir Morlaix Nantes Nice Ouistreham Paimboeuf Paimpol Paris Pauillac Pont Abbe Bouc Jerome Vendres Vecchio Propriano Quimper Rochefort Roscoff Rouen Sables Olonne Sete St.Brieuc St.Jean Luz St.Louis du Rhone St.Malo St.Nazaire St.Servan St.Valery en Caux Somme Strasbourg Tonnay Charente Toulon Treguier Treport Trouville Verdon GA Gabon Cap Lopcz Gamba Libreville Lucina Owendo Gentil GB United Kingdom Aberdeen Aberdour Aberdovery Aberystwyth Alderney Amlwch Annalong Annan Anstruther Appledore Arbroath Ardglass Ardrishaig Ardrossan Avonmouth Ayr Bangor Barmouth Barnstaple Barrow Barry Barton Beaumaris Beliast Berwick Bideford Birkenhead Blyth Boston Bridgwater Bridlington Bridport Brightlingsea Brighton Bristol Brixham Bromborough Dock Buckie Burghead Burntisland Caernarfon Campbeltown Cardiff Carrickfergus Castletown Charlestown Colchester Coleraine Connah Quay Corpach Cowes Cromarty Dartmouth Dingwall Douglas Dover dumfries Dunbar Dundee Dundrum Ellesmere Exeter Exmouth Eyemouth Falmouth Fawley Felixstowe Finnart Fishguard Fleetwood Folkestone Fowey Fraserburgh Gainshborough Garlieston Garston Girvan Glasgow Glenarm Gloucester Goole Gourock Grangemouth Gravesend Great Yarmouth Greenock Grimsby Gunness Wharf Hartlepool Harwich Hayle Heysham Holyhead Hound Hull Hunterston Immingham Invergordon Inverness Ipswich Irvine Isle Grain Kilkeel Killingholme King Lynn Kirkcaldy Kyle Lochalsh Lame Lancaster Largs Larne Leith Lerwick Littlehampton Liverpool Llanddulas Llanelli Loch Boisdale Maddy Lochaline Pier London Londonderry Looe Lossiemouth Lowestoft Lybster Lydney Macduff Maldon Mallaig Manchester Methil Mevagissey Middlesbrough Millom Minehead Mistley Montrose Mostyn Nairn Neath Newburgh Newcastle Newhaven Newlyn Newport Newry North Sunderland Norwich Oban Pdstow Palnackie Par Parkeston Partington Peel Pembroke Penmaenmawr Penryn Penzance Perth Peterhead Plymouth Poole Askaig Ellen St.Mary Talbot William Portbury Porthmadog Portishead Portladn Bill Portree Portrush Pwllheli Queenborough Queensferry Rainham Ramsey Ramsgate Redcar Rhyl Richborough Ridham Rochester Rosyth Rothesay Runcorn Rye Sandwich Sanudersfoot Scalloway Scapa Flow Scrabster Seaham Selby Sharpness Shell Haven Shoreham Southampton Southend St.Helier St.Ives St.Margaret Hope St.Peter Stanlow Stockton Stonehaven Stornoway Strangford Stranraer Stromness Sullom Voe Sutton Bridge Swansea Tarbert Teesport Teignmouth Tenby Tetney Thurso Tilbury Tobermory Topsham Torquay Totnes Troon Truro Tyne Ullapool Warkworth Warren Watchet Babylon Dacca Ealing Fanning Gaberones Haerbin Iberia Jackson Kabul Labrador Mass Nagasaki Oahu Pacific the Qatar Rabat Saarland Tabriz Ucayali Wake Yalta Zagreb Alborg Babylonia Caernarvonshire Dagenham Eastbourne Hague The Iceland Jadotville Kalahair Desert Labuan Macao Macau Nagoya Oakland Padua Qatif Katif Racine Sabah Tadzhikistan Tajikistan Uganda Vaduz Wales Xilinhot Yalu Zagros Abadan Back Cagliari Dahomey Ferg ana Gaborone Haifa Ida Jaipur Kalgoorlie Laccadive Macassar Maka sar Nagpur Pakistan Qinghai Radnorshire Sabine Taegu Ukraine Valdai Hills Walsall Ximalaya Yaounde Yaunde Zaire Badajoz Cairo Dakar East Ham Fermanagh Galapagos Hailar Idaho Jakarta Djakarta Kaliningrad Lachlan Mackenzie Naha Oceania Palau Rainier Mount Sacramento Taugs Ulan Ude Waltham Xingu Zama Aberdeenshire Baden Cathness Dakota lothian Galdhopiggen Haiphong Iharka Jamaica Kama Ladoga Madagascar Nairnshire Palembang Quebec Rakaposhi Tahiti bator Valenciennes Wanganui Xining Yawata Zambezi Zambesi Abidjan Baffin Dallas Eastern Samoa Fertile Cerscent Galilee Haiti Illampu James Kamchatka Peninsula Lagos Maderia Nairobi Oder Palermo Queen Alexandra Range Raleigh Saint Etienne Taichung Ulanhot Valladolid Warrington Xinjiang Yellowstone Zambia Abilene Bag dad Calcutta Damascus Fife Galveston Hakodate Illinois Jamshedpur Kampala Guaria Madras Namibia Odessa Palestine Maud Mountains Rangoon Sakhalin Tai Ulster letta Warszawa Xizhang Yemen Zanzibar Dhabi Baguio Calgary Danger Edinburg Fifeshire Galway Haleakala Incahuasi Japan Kampuchea Lahore Madrid Nanchang Offaly Mallorca Queensland Rantemario Salado Tainan Umbria Warwickshire Yenangyaung Zaporozje Accra Akkra Bahamas Cali Danube Edinburgh Gambia Halifax Inchon Sea Kanchenjunga Lanarkshire Madura Nancy Offenbach Palmerston Quincy Ravenna Salamanca Taipei Arab Emirates Vancouver Washington Yenisey Yenise Zealand Aconcagua Calicut Danzig Edmonton Finisterre Gambier Halmstad India Japura Kansas Lancashire Maebashi Mayebashi Nanda Devi Ogasawara Palmyra Quito Rawalpindi Salem Shan States America Vatican City State Waterbury Yinchuan Zetland Acropolis Bahrain Bahrein California Dardanelles Edward lake Ganges Indiana Jarvis Kaohsiung Langson Lang Son Mafeking Nanga Parbat Ohio Pamir Red River Salford Taitung Upper Volta Vatnajokull Waterford Yokohama Zheng Zhou Adana Baikal Lake Gulf Dar Salaam Finsteraarhorn Gangtok Hamilton Indianapolis Jassy Karachi Lanzhou Magdalen Nan Hai Ojos Panama Salisbury Taiwan sala Vaud Weimar Yokosuka Zhu Jiang Addis Ababa Baku Callao Darien Eire Flanders Gannett Peak Hammerfest Indian Ocean Java Karaganda Laos Magdalena Nanjing Oka Panie Regina Salonika Salonica Strait Ural Venezuela Welland York Zhumulangmafeng Adelaide Balearic Cambridge Darjeeling Elba Flattery Gansu Hammond Indochina Jefferson Karakoram Lapland Magdeburg Nanning Okayama Papua Reims Rheims Salop Taiyuan Uruguay Venice Wellesley Yorkshire Zimbabwe Aden Bali Cambridgeshire Darling Elbe Flint shire Garonne Hampshire Indonesia Jena Karamay Megellan Okhotsk New Guinea Renfrewshire Salvador Tallin Urumqi Verdun Wellington Yuannan Zomba Adirondacks Balikpapan Camden Darlington Elbert Florence Gary Hampstead Indore Jervis Kariba Lhasa Maggiore Nantucket Okinawa Paraguay Reunion Salween Tamatave Usumbura Vermont Australia Yucatan Zugspitze Adriatic Balkan Darmstadt Elborus Flores Gascony Hangzhou Indus Jesselton Kashmir Selle Magnitogorsk Naples Oklahoma Paramaribo Reykjavik Salzburg Tampere Utah Versailles Isles Yugoslavia Jugoslavia Zuider Zee Aegean Balkans Cameroun Darwin Elburz Mts Florida Gasherbrum Hanover Hannover Innsbruck Jiangsu Katadin Lashio Makdstone Narbada Oldham Parana Rhaetian Alps Samaria Tampico Utica Vesuvius Yukon Zurich Aetna Etna Balk ash Campania Dauphine Eleusis Gateshead Noi Hanoi Jiangxi Katanga Las Palmas Maikop Narvik Olympic Paranaiba Rhine Samarkand Tananarive Utrecht Viborg Vyborg West Glamorgan Territory Afghanistan Baltic Canada Davenport Elisabethville Foraker Gdynia Harbin Iona Jibuti Katar Lassen Maine Nassau Olympus Paricutin Rhode Tanganyika Uzbekistan Vichy Indies Africa Baltimore Canadian Davis Stait Ellice Fort Lamy Geneva Harney Ionia Jilin Kathmandu Khatmandu Vegas Natal Omaha Rhodesia Samos Tangier Vicksburg Lothian Agra Baluchistan Zone Dawna Misti Genoa Hartford Iowa Jinan Katowice Latakia Majorca Nauru Oman Parma Rhodope Samothrace Tan Shui Tansul Westmeath Ahaggar Bamako Canary Dawson Georgetown Harvard Jinsen Kawaikini Latium Makalu Navarre Omdurman Parnassus Sanaa Tanzania Westmorland Bandar Seri Begawan Canaveral Dayton Franklin Georgia Harz Ipoh Johannesburg Kazak satan Latvia Malabar Coast Nazareth Omsk Paros Richmond Bernardino Taranaki Vienna Virginia Ban jarmasin Dead Emi Koussi Fraser Hastings Johore Kazbek kasbek Lausanne Malabo Ndjamena Onega Parthia Riga Diego Taranto Vientiane Wexford Akron Bandung Bandoeng Canberra Dearborn Emperor Freetown Ghana Iran Jonkoping Kebnekaise Lawrence Malacca Malakka Nebraska Ontario Patagonia Rindjain Sanford Tarawa Vietnam Viet Nam Weymouth Alabama Banffshire Candia Deccan Enderby land Freiburg Ghats Hawaii Iraq Irak Jordan Keelung Lebanon Negoiul Oporto Paterson Janeiro Francisco Tashkent Tashkend Whales Alameda Bangalore Delano England Fremantle Ghent Hawaiian Ireland Julian Keewatin Leeds Negri Sembilan Oraefajokull Patna Gorgonio Tasmania White Alaska Cantabrian Deaware English Channel Fresno Gibraltar Hawke Irish Jungfrau Keighley Leghorn Malagasy Oran Pavia Rivera Sanger Cristo Tasman Virgin Whitney Albania Bangkok Canterbury Delhi Entebbe Friendly Gila Hebei Irkutsk Jurua Kelantan Neiges Piton des Oregon Peace Riyadh Jose Taunton Vistula Wicklow Albany Bangladesh Canton Delphi Ephesus Frisian Gillbert Hebrides Irrawaddy Kent Leicester Malawi Nei Menggu Otinoco Pearl Harbor Roanoke Juan Taurus Vitim Wigan Alberta Bang Cod Demavend Epsom and Ewell Front Gillingham Hecate Ischia Kentucky Leicestershire Malaya Neisse Orissa Pechora Robson Marino Tayside Vitoria Wigtownshire Albuquerque Bani Hatteras Denbighshire Equatorial Fuji yama Gironde Heidelberg Islamabad Kenya Leinster Malay Archipelago Nelson Orizaba Pecos Rochdale Remo Tegucigalpa Vladivostok Wilmington Aldan Banjul Horn Erebus Fujian Hefei Wight Kerch Leipzig Malaysia Federation Nepal Orkney Peebles Tehran Teheran Volcano Wiltshire Aleutians Barbados Good Erie Fukuoka Heilongjiang Israel Kerguelen Leitrim Maldives Netherlands Orleans Pembrokeshire Rocky Ana Tel Aviv Volga Wimbledon Alexander Barbuda Town Capetown Denver Eritrea Funafuti Helicon Istanbul Kerintji Leix Laoighis Male Neva Orohena Penang Romania Isabel Tenerife Vorkuta Winchester Derbyshire Esdraelon Plain Fundy Gloucestershire Helsingor Italy Kerry Lena Mali Nevada Orpington Pensng Rome Tennssee Vosges Windhoek Barisan Moutains Capri Des Moines Essen Gobi Ivanovo Kew Leningard Malmo Newark Osage Penghu Romford Texas Windsor Algiers Baroda Caracas Detroit Essex Godavari Helvetia Ivory Key Leopoldville Malta Britain Osaka Pennine Alpa Rosa Monte Thailand Windward Devon Estonia Esthonia Gold Henan Izmir Khabarovsk Lepontine Man Brunswick Oslo Pennsylvania Roscommon Sao Franciso Thames Winnipeg Kuwait Bartle Frere Cardiganshire Devonport Gorki Gorky Hendon Iztaccihuatl Kharkov Lespos Managua Caledonia Ossa Perak Paulo Thar Dester Wisconsin Allahabad Basel Caribbean Gosport Heng Khartum Khartoum Lesotho Manama Ostrava Perlis Ross Thebes Witwatersrand Allentown Bashi Carlow Dhaulagiri Eton Goteborg Hereford Worcester Khyber Pass Lesser Antilles Manaus Otago Perm Principe Thimbu Wolverhampton Alma Ata Basra Carmarthenshire Dimond Euboea Gothenburg Herefordshire Leven Otranto Persia Rostov Sapporo Thousand Worcestershire Almaden Basutoland Carolina Dian Bien Phu Euphrates Grampian Hermon Kielce Lexington Mandalay Newfoundland Ottawa Persian Rotherham Saragossa Thrace Wrath Bataan Caroline Dijon Eurasia Hertfordshire Kiev Kiyev Leyton Manhattan Ouachita Rotterdam Saratoga Thule Wuhan Alsaca Batan Carpathian District Columbia Europe Granada Hessen Kigali Liaoning Manila Ouagadougou Perthshire Saratov Thun Wulumuqi Altai Batangas Carstensz Evans Grand Teton Highland Kildare Liberia Manitoba Oviedo Peru Rovaniemi Sarawak Thuringian Plateau Wyoming Amazon Batavia Dnieper Evanston Granite Himalay Kilimanjaro Jersey Owen Pescadores Roxburghshire Sardinia Tianjin Bath Casablanca Dniester Everett Grays Hindustan Hindostan Kilkenny Libya Mansfield Mexicc Oxfordshire Peshawar Ruanda Sasebo Tiber Amiens Bathurst Cascade Doha Bear Hiroshima Kimberley Lido Mantua Petersburg Ruapehu Saskatchewan Tibesti Amman Battersea Caspian Eyre Hobart Kinabalu Kinabulu Liechtenstein Maputo South Petsamo Rubicon Sardi Arabia Tiflis Amritsar Batumi Castries Dividing Hoboken Kincardineshire Liege Maracaibo Philadelphia Rudolf Sawatch Tigris Amsterdam Bavaria Catalonia Doncaster Greater Chi Minh Kings Lille Maranon Philippines Rugby Saxony Timor ship canal Bavarian Catania Donegal Slave Hohhot Kingston Liongwe Marcus Niagara Phnom Penh Pnom Ruhr Scafell Pike Tipperary Amu Darya Catskill Donets Smoky Hokkaido Kingstown Lima Marcy Falls enicia Russia Scandinavia Tirana Anatolia Beaufort Caucasia Dong Greece Holland Kingross Mariana Niamery Phoenix Rutland Tisza Beaumont Caucasus Don Green Hollywood Kinshasa Limerick Marie Byrd Land Nicaragua Pidurutalagala Schenectady Tobago Ancohumia Bechuanaland Cavan Dongting Greenland Holyoke Kintyre Limpopo Maritime Pietermaritzburg Ruwenzori Schiedam Tobol Andalusia Bedfordshire Cavite Dorset Holy See Kirg Lincolnshire Markham Nicobar Pikes Rwanda Schleswing Holstein Tocantins Andaman Beijing Cayman islands Greenwich Honduras Kiribati Lingayen Marlborough Nicosia Pillcomayo Schouten Togo Andes Beirut Bayrut Cebu Douro Grenada Hong Kong Hongkong Kirkcudbrightshire Lipair Marguesas Niger Pilsen Ryukyu Schuylkill Tokyo Andizan Andizhan Belem Celebes Grenoble Honiara Kirkpatrick Lisbon Marsala Nigeaia Pisa Scilly Toledo Andorra Belfast Central Doverfjell Honolulu Kirkuk Lithuania Niigata Pittsburg Scotland Tomsk vella Belgium Provinces Benar Down Grossglockner Honshu Kitchener Little Missouri Marshall Nijmegen Nimeguen Pittsburgh Scythia Tonga Andros Belgrade Ceuta Drakensberg Gronzy Hood Kjolen Martha Vineyard Nile Seattle Aneto Pico Benares Banaras Ceylon Dresden Guadalupe Hornsey Klondike Locarno Martinique Ningxia Ploesti Sedan Tonging Angara Bengal Chad Duala Guadeloupe Hua Klyuchevskaya Lodz Maryland Nizhni Tagil Seine Toronto Angkor Chamonix Dublin Guam Huai Kobe Logan Maseru Norfolk Selangor Anglesey Anglesea Benin Champagne Dubrovnik Guangdong Huang Kokand Loire Maskat Masqat Muscat Normandy Poitiers Selkirk Torres Angola Berchtesgaden Changchun Dudley Guangxi Kola Lombok Massachusetts Norrkoping Poland Selkirkshire Toubkal Anguilla Bergen Chang Jing Duff Guangzhou Huascaran Kolyma kolima Lome Massive Northampton Polynesia Semarang Angus Bering Changsha Duluth Guantanamo Hubei Komsomolsk Lomond Matterhorn Pomona Sendai Toulousc Anhui Berkeley Dumbarton Oaks Guatemala Huddersfield Korea Mauga Sili Borneo Pompeii Senegal Tours Anjou Berkshire Charleston Dumbartonshire Hudson Korla Mauna Kea Pondicherry Seoul Toyama Ankara Berlin Charlotte Dumfries Galloway Hue Kosciusko Longford Loa Serbia Trafalgar Annapolis Bermuda Chartres Huhehaote Kowait Longs Mauritania Northern Poona Transcaucasia apurna Bern Chatham Bissau Huila Kowloon Lorain Mauritius Popocatepetl Sevres Trengganu Ann Arbor Berwickshire Chaud Doc Dunedin Guiyang Krasnovodsk Lorne Firth Mayo Platte Seward Trier Antananarivo Bessarabia Chautauqua Guizhou Humberside Krasnoyarsk Lorraine Mbabane Seychelles Trieste Antarctic Bethlehem Chemnitz Durban Gunong Tahan Hunan Kristiansand Los Angeles Mckinley Northumberland Arthur Sham Trinidad Antarctica Bhamo Chengdu Durham Guyana Hungary Krivor Krivoy Rog Lost clure Territories Prince Shandong Antigua Bhutan Cherrapunji Gwent Huntingdon Krons tadt Meath Louis Shanghai Tripoli Bialystok Chesapeake Dutch Gwynedd Huntingdonshire Kuala Lumpur Louisiana Mecca Mekka Norton Sound Moresby Shanxi Trondheim Anti Chesire Dvina Huron Kuching Lourenco Marques Medina Norway Troy Billiton Chester Hyderabad Kuibyshev Kuybyshev Louth Mediterranean Norwegian Novo Sharjah Tsushima Chesterfield Dyfed Kunlun Lowell Mekong Rico Sharon Tuapse Antrim Birmingham Cheyenne Dykh Tau Kuming Luanda Melanesia Nottingham Shasta Tucson Antwerp Biscay Chicago Kuqa Luang Prabang Melbourne Shawnee Tula Apennines Bishkek Chihuahua Kursk Memphis Nouakchott Portugal Sheba Tunis Apia Bismarck Kuweit Lublin Menai Nova Scotia Posen Sheffield Tunisia Apo Chimborazo Kuznetsk Lubumbashi Menam Novosibirsk Potomac Shenyang Turin Appalachian Kyoto Lucerne Mendoza Nukualofa Potosi Shetland Turkey Bizerte Chiriqui Kyrshu Lucknow Mercedario Nuneaton Potsdam Shijiazhuang Turkmenistan Arabian Blackburn Chirripo Lulea Merionethshire Nyasa Poyang Shikoku Chita Lusaka Meroe Nyasaland Poznan Shimonoseki Tuscany Toscana Aragon Black Chittagong Luton Merseyside Prague Shiraz Tuvalu Araguaia Araguaya Blackpool Chkalov Luxemb urg Merthyr Tydfill Shkara Tyler Aral Choson Luzon Meshed Shrewsbury Wear Ararat Blagoveshchensk Christchurch Lydia Mesopotamia Pretoria Shropshire Tynemouth Archangel Blanc Christmas Messina Siam Tyrol Tirol Arctic Bland Mont Chuckchee Lyons Metz Princeton Siberia Tyrone Arden Churchill Mexico Providence Sichuan Tyrrhenian Ardennes Bloemfontein Chu Prussia Sicily Arequipa Blue Cimarron Pueto Sidon Argentina Bogota Cincinnati Miami Pulog Siena Sienna Argyllshire Ciscaucasia Michigan Punakha Sierra Leone Arizona Bokhara Clare Micronesia Punjab Panjab Madre Oriental Arkansas Bolivia Cleveland Middlesex Purbeck Arlington Bologna Clifton Mid Purus Sikkim Armagh Bolton Clwyd Midlothian Pusan Silesia Armenia Bombay Midway Pyongyang Simla Arno Bonin Coats Mieres Pyrenees Simplon Arras Cocos Milan Sinai Milk Singapore Ascension Borders Millwaukee Singkep Ashanti Colombo Mindanao Sinuiju Asia Bosporus Colorado Minneapolis Sioux Minor Minnesota Skye Asmara Botany Minorca Sligo Assam Bothnia Columbus Minsk Smethwick Assyria Botswana Como Mississippi Hill Asuncion Bougainville Comoro Snake Aswan Ass uan Boulder Compiegne Mitchell Society Atbara Conakry Mobile Socotra Sokotra Athabasca Athabaska Bournemouth Concepcion Mogadishu Sofia Athens Bradford Congo Moldavia Solomon Athos Brandenburg Connacht Molokai Solway Frith Atlanta Brasilia Connecticut Molotov Somalia Atlantic Bratislava Constantine Moluccas Somaliland Brazil Constantinople Mombasa Somali Atlas Brazos Constantsa Monaco Somerset Attica Brazzaville Monaghan Somerville Auckland Coolgardie Mongolia Song Augusta Breslau Monmcutshire Austin Coral Monrovia Australasia Bretagne Cordillera Montana Auwtralia Bridgetown Cordoba Carto Australian Corfu Montenegro Austria Brisbane Corinth Montevideo Austronesia Cork Montgomeryshire Aux Sources Corno Montmartre Soviet Union Avernus British Cornwall Montpelier Avon Brno Corrientes Montreal Sparta Ayrshire Bronx Corsica Montserrat Spitsbergen Ayutthaya Brooklyn Morava Srilanka Azerbaijan Brunei Cote Azur Morayshire Srinagar Azores Cotonou Morocco Stafford Azov Brussels Cotopaxi Moroni Staffordshire Bucharest Coventry Moscow Stalingrad Buckinghamshire Cradle Mosul Stalino Budapest Cranston Moulmein Stalin Crefeld Mozambique Stalinsk Buenos Aires Crete Mulhacen Stamford Buffalo Crewe Munich Bug Crimea Munster Stassfurt Bujumbura Croatia Murchison Stavanger Cro Magnon Murmansk Bernard Bungay Crosby Murry Christopher Burma Croydon Musala Clar Burundi Elas Bute Cumberland Mycenae Stettin Cumbria Myitkyina Stewart Byelorussia Cumbuian Mytilene George Cyclades Got hard Tunnel Helena Cyrenaica Stirlingshire Czechoslovakia Johns Stockholm Stockport Paul Stratford Strathclyde Stuttgart Sudan Sudbury Sudety Isthmus Suffolk Sulu Sumat Sunda Sun moon Superior Surabaja Surabaya Surat Surbiton Surinam Surrey Susquehanna Sussex Sutherland Sutlei Suvalbard Sverdlosk Swaziland Sweden Swidon Switzerland Sybaris Sydney Syracuse Syr Darja Syria 
/;
@names = qw(
Acharya
Agarwal
Agate
Aggarwal
Agrawal
Ahluwalia
Ahuja
Amble
Amin
Anand
Andra
Anne
Anthony
Apte
Arora
Arya
Atwal
Aurora
Babu
Badal
Badami
Bahl
Bahri
Bail
Bains
Bajaj
Bajwa
Bakshi
Bal
Bala
Balakrishnan
Balan
Balasubramanian
Balay
Bali
Bandi
Banerjee
Banik
Bansal
Barad
Baral
Baria
Barman
Basak
Bassi
Basu
Bath
Batra
Batta
Bava
Bawa
Bedi
Beharry
Behl
Ben
Bera
Bhagat
Bhakta
Bhalla
Bhandari
Bhardwaj
Bhargava
Bhasin
Bhat
Bhatia
Bhatnagar
Bhatt
Bhattacharyya
Bhatti
Bhavsar
Bir
Biswas
Boase
Bobal
Bora
Borah
Borde
Borra
Bose
Brahmbhatt
Brar
Buch
Bumb
Butala
Chacko
Chad
Chada
Chadha
Chahal
Chakrabarti
Chakraborty
Chana
Chand
Chanda
Chander
Chandra
Chandran
Char
Chatterjee
Chaudhari
Chaudhary
Chaudhry
Chaudhuri
Chaudry
Chauhan
Chawla
Cheema
Cherian
Chhabra
Chia
Chohan
Chokshi
Chopra
Choudhary
Choudhry
Choudhury
Chowdhury
Comar
Contractor
Dada
Dalal
Dani
Dar
Dara
Das
Dasgupta
Dash
Dass
Date
Datta
Dave
Dayal
De
Deep
Deo
Deol
Desai
Deshmukh
Deshpande
Devan
Devi
Dewan
Dey
Dhaliwal
Dhar
Dhawan
Dhillon
Dhingra
Dial
Din
Divan
Dixit
Doctor
Dora
Doshi
Dua
Dube
Dubey
Dugal
Dugar
Dutt
Dutta
D’Alia
Dyal
Edwin
Gaba
Gade
Gala
Gandhi
Ganesan
Ganesh
Ganguly
Gara
Garde
Garg
George
Gera
Ghose
Ghosh
Gill
Gobin
Goda
Goel
Gokhale
Gola
Gole
Golla
Gopal
Goswami
Gour
Goyal
Grewal
Grover
Guha
Gulati
Gupta
Halder
Handa
Hans
Hari
Harjo
Hayer
Hayre
Hegde
Hora
Issac
Iyengar
Iyer
Jacob
Jaggi
Jain
Jani
Jayaraman
Jha
Jhaveri
Johal
Joshi
Kadakia
Kade
Kakar
Kala
Kale
Kalita
Kalla
Kamdar
Kanda
Kannan
Kant
Kapadia
Kapoor
Kapur
Kar
Kara
Karan
Kari
Karnik
Karpe
Kashyap
Kata
Kaul
Kaur
Keer
Khalsa
Khanna
Khare
Khatri
Khosla
Khurana
Kibe
Kohli
Konda
Korpal
Koshy
Kota
Kothari
Krish
Krishna
Krishnamurthy
Krishnan
Kulkarni
Kumar
Kumer
Kunda
Kurian
Kuruvilla
Lachman
Lad
Lal
Lala
Lall
Lalla
Lanka
Lata
Lodi
Loke
Loyal
Luthra
Madan
Magar
Mahabir
Mahadeo
Mahajan
Mahal
Maharaj
Majumdar
Malhotra
Mall
Mallick
Mammen
Mand
Manda
Mandal
Mander
Mane
Mangal
Mangat
Mani
Mann
Mannan
Manne
Maraj
Masih
Master
Mathai
Mathew
Mathur
Matthai
Meda
Mehan
Mehra
Mehrotra
Mehta
Meka
Memon
Menon
Merchant
Minhas
Mishra
Misra
Mistry
Mital
Mitra
Mittal
Mitter
Modi
Mody
Mogul
Mohabir
Mohan
Mohanty
Morar
More
Mukherjee
Mukhopadhyay
Muni
Munshi
Murthy
Murty
Mutti
Nadig
Nadkarni
Nagar
Nagarajan
Nagi
Nagy
Naidu
Naik
Nair
Nanda
Narain
Narang
Narasimhan
Narayan
Narayanan
Narine
Narula
Natarajan
Nath
Natt
Nayak
Nayar
Nazareth
Nigam
Nori
Oak
Om
Oommen
Oza
Padmanabhan
Pai
Pal
Palan
Pall
Palla
Panchal
Pandey
Pandit
Pandya
Pant
Parekh
Parikh
Parmar
Parmer
Parsa
Patel
Pathak
Patil
Patla
Pau
Peri
Persad
Persaud
Philip
Pillai
Pillay
Pingle
Prabhakar
Prabhu
Pradhan
Prakash
Prasad
Prashad
Puri
Purohit
Radhakrishnan
Raghavan
Rai
Raj
Raja
Rajagopal
Rajagopalan
Rajan
Raju
Ram
Rama
Ramachandran
Ramakrishnan
Raman
Ramanathan
Ramaswamy
Ramesh
Ramkissoon
Ramnarine
Rampersad
Rampersaud
Ramroop
Ramson
Rana
Randhawa
Ranganathan
Rao
Rastogi
Ratta
Rattan
Ratti
Rau
Raval
Ravel
Ravi
Ray
Reddy
Rege
Rout
Roy
Sabharwal
Sachar
Sachdev
Sachdeva
Sagar
Saha
Sahni
Sahota
Saini
Salvi
Sama
Sami
Sampath
Samra
Samuel
Sandal
Sandhu
Sane
Sangha
Sanghvi
Sani
Sankar
Sankaran
Sant
Saraf
Saran
Sarin
Sarkar
Sarma
Sarna
Sarraf
Sastry
Sathe
Savant
Sawhney
Saxena
Sehgal
Sekhon
Sem
Sen
Sengupta
Seshadri
Seth
Sethi
Setty
Sha
Shah
Shan
Shankar
Shanker
Sharaf
Sharma
Shenoy
Shere
Sheth
Shetty
Shroff
Shukla
Sibal
Sidhu
Sing
Singh
Singhal
Sinha
Sodhi
Solanki
Som
Soman
Soni
Sood
Sridhar
Srinivas
Srinivasan
Srivastava
Subramaniam
Subramanian
Sule
Sundaram
Sunder
Sur
Sura
Suresh
Suri
Swaminathan
Swamy
Tailor
Tak
Talwar
Tandon
Taneja
Tank
Tara
Tata
Tella
Thaker
Thakkar
Thakur
Thaman
Thomas
Tiwari
Toor
Tripathi
Trivedi
Upadhyay
Uppal
Usman
Vaidya
Vala
Varghese
Varkey
Varma
Varty
Varughese
Vasa
Venkataraman
Venkatesh
Verma
Vig
Virk
Viswanathan
Vohra
Vora
Vyas
Wable
Wadhwa
Wagle
Wali
Walia
Walla
Warrior
Wason
Yadav
Yogi
Yohannan
Zacharia
Zachariah
Adani	Vaishnavi	Sunthari	Shruti	Sangem	Ramalingam
Amarnath	Vallath	Suranjan	Shukla	Sanjna	Ramamuthe
Arasaratnam	Vamsi	Surendar	Sidda	Sankuratri	Ramanuja
Balakrishnan	Vaninadha	Surnilla	Sira	Sanu	Ramaswami
Bedi	Varganti	Surupa	Sivaram	Sapra	Ramiah
Bhaskar	Varuni	Suryanarayanan	Smita	Sarasvan	Ramnarine
Bisht	Vasudha	Suvrata	Sohal	Sardesai	Rana
Bux	Vattyam	Swani	Somasundara	Sarmistha	Rangaraj
Chande	Vedula	Swetha	Sompalli	Sashi	Ranhotra
Chandramouleeswaran	Veerasamy	Tamhane	Sophia	Sathaye	Rantidev
Chandrasekhar	Vemireddy	Tanu	Soumyabrata	Satinder	Ravandur
Charan	Venkatasubramani	Tapi	Sowrirajan	Satyavati	Raviraj
Chaudhry	Venkateswarn	Tasha	Sreedharan	Saurin	Rebani
Chellaiah	Verma	Thadigiri	Sreenivasan	Saxena	Renuka
Cherukuri	Vidvan	Thangaraj	Srijata	Sekariapuram	Rewari
Chetlapalli	Vijaya	Thirunarayan	Srila	Senagala	Rishiyur
Chidamber	Vijayarangan	Thukral	Sritharan	Seshaanath	Roshni
Chirag	Vikul	Thyagarajan	Srivatsan	Sethuraman	Rudrani
Chittor	Vinita	Tikoo	Subbanna	Shadilya	Rupesh
Choudhury	Viraf	Trikha	Subhaga	Shaila	Sachin
Dalmiya	Virendra	Trusha	Subram	Shalabh	Sadhwani
Dasari	Visalakshi	Tushar	Subramanya	Shamsher	Sahadev
Dawar	Vishwa	Uday	Suchin	Sharma	Saibal
Dhaliwal	Viswanath	Udutha	Sudesh	Shastri	Saini
Dhruba	Vivek	Ulla	Sudhakar	Shikha	Sajja
Dinkar	Vyapari	Unnikrishnan	Sugriva	Shinu	Salil
Dristi	Yaksha	Urimindi	Sukanya	Shivakumar	Samderiya
Durmada	Yamura	Vadakke	Sulagna	Shourov	Sampath
Elango	Yateen	Vaidya	Sumila	Shreeyash	Sandeep
Eswarapu	Yelsangikar	Vaithu	Suneina	Shripati	Sangam
Gajaren	Yogesh	Valli	Suppiah	Shubha	Sangha
Ganapathy	Advani	Vanchinathan	Surapaneni	Shukta	Sanjukta
Gargeya	Amra	Vanita	Surendran	Siddhi	Sanmugasunderam
Ghani	Aron	Varghese	Surpur	Sita	Sanyogita
Ghosh	Banerjee	Vasava	Suryadevara	Sivaramakrishnan	Sapthotharan
Giridhar	Behari	Vasudhara	Susarla	Smitha	Sarasvati
Goel	Bhatt	Vavveti	Swagato	Sohoni	Sarika
Gopinath	Biswas	Veena	Swarnkar	Somasundaram	Saru
Govindasvamy	Cansai	Veerender	Tagore	Somu	Sashti
Guha	Chander	Vemuganti	Tamragouri	Sorabhjee	Sathiamoorthy
Guneratne	Chandramouli	Venkatasubramanian	Tanuja	Soundar	Satrujit
Guramurthy	Chandrasekharan	Venkatraman	Tarang	Sraddha	Satyavolu
Gutta	Charu	Vibha	Tatat	Sreehari	Savarna
Harku	Chaudhury	Vidwans	Thakur	Sreeram	Scindia
Himanshu	Chellappa	Vijayabhas	Thiagarajan	Srijoy	Sekhar
Honnenahalli	Cherupara	Vijayashree	Thiruvengadathan	Srimal	Senajit
Imani	Chhachhi	Vilok	Thundayal	Srivas	Seshadri
Jafferbhoy	Chikodi	Vinuta	Tickoo	Sruthi	Setna
Jaishree	Chirimar	Viraj	Tina	Subbarao	Shafiqul
Jasmit	Chitturu	Viresh	Trisanu	Subhangi	Shailaja
Jayaram	Choughoy	Vish	Tuhina	Subramani	Shalaby
Jeyaseelan	Dama	Vishwamber	Tuteja	Subramanyan	Shan
Jitesh	Dasgupta	Viswanathan	Udayan	Suchitra	Sharmistha
Junanker	Dehiya	Vivekanand	Ujjwal	Sudesha	Shaukat
Kachwaha	Dharuna	Vyshali	Umakanta	Sudhanshu	Shiladitya
Kaith	Dhupam	Yalamanchi	Upender	Suhas	Shirish
Kallichuran	Dinkerrai	Yanamandra	Utpal	Sukarman	Shivani
Kambhatla	Dua	Yauvani	Vadlamani	Sultana	Shraddha
Kanetkar	Duvvoori	Yeluri	Vairaja	Sumon	Shrestha
Kanwar	Elayavalli	Yogish	Vajpayee	Sunny	Shrirang
Karumuri	Gadde	Agarwal	Vallurupalli	Supriya	Shubhabrata
Kathiravan	Gajendra	Anand	Vandita	Surati	Shurpali
Kaushik	Ganesh	Badesha	Varadarajan	Surendranath	Sidhu
Keerthana	Garikapaty	Barendran	Varki	Surti	Sitha
Keshava	Ghazali	Bhagyamma	Vashisth	Suryanarayama	Sivaraman
Keyush	Ghoshal	Bhatti	Vasuman	Susumna	Snehasis
Khodaiji	Giridhara	Boparai	Vedanga	Swami	Solaimathi
Kittur	Goenka	Chandak	Veera	Swathi	Somatra
Kodi	Gopivallabha	Chandna	Vellanki	Taksa	Soni
Kolala	Govindraj	Chandrark	Venkataraghavan	Tandekar	Sornam
Kondapaneni	Gujral	Chandrashekar	Venkatesann	Tapan	Soundrapandian
Koppala	Gungabissoon	Chatterjee	Venu	Tarit	Sravan
Kosuri	Gurbux	Chawd	Vichur	Tatavarti	Sreekanth
Kripa	Halder	Chengelpet	Vidyarthi	Thamma	Sreerupa
Kulasekaran	Haryadi	Chetan	Vijayakumar	Thimanniya	Srikaran
Kumur	Hindocha	Chheda	Vijaykumar	Thogulva	Srinath
Kurapati	Huggahalli	Chinnakannan	Vineet	Thundyil	Srivastav
Kusagra	Indrani	Chitrangda	Vipin	Tikaram	Sruti
Lahan	Jaffrey	Chohan	Virani	Tirumalai	Subbarat
Lalitesh	Jaisimha	Chowdry	Virini	Trishna	Subhendu
Latesh	Jaspal	Darsha	Vishal	Tumkur	Subramaniam
Laxmanan	Jayasinghe	Datla	Visvakarman	Tyagi	Subrata
Loy	Jignesh	Deol	Visweswaramurthy	Uddin	Sudarsan
Madan	Joardar	Dhawan	Vootla	Ujjwala	Sudeshna
Madugula	Jyothsna	Dibyendu	Waman	Umesh	Sudhansu
Mahajan	Kadak	Diwan	Yalamanchilli	Upendra	Sujan
Mahatapa	Kakde	Durai	Yashodhar	Utpat	Suketu
Maitryi	Kalluri	Edulbehram	Yavatkar	Vaibhav	Suman
Makarand	Kambli	Emankumar	Yesh	Vaisakhi	Sunanda
Malipatlolla	Kanitkar	Gadepalli	Zahin	Vajpeyi	Sunondo
Mallya	Kapadia	Gala	Agrawal	Valsan	Suprotik
Manasa	Karuppia	Gangadharan	Ankola	Vani	Suravinda
Mandar	Kathrada	Gavarasana	Bahl	Varahabhotla	Suri
Manekshaw	Kawediya	Ghemawat	Barot	Varsha	Suruchi
Mangeshkar	Keerthi	Ghouse	Bhanghoo	Vasi	Suryanarayan
Manjanatha	Keshavan	Girish	Bhoola	Vasumati	Sutapa
Mankad	Khadri	Goli	Buchar	Vedati	Swaminathan
Mantri	Khot	Gorawala	Chandan	Veeramany	Swati
Marisa	Kitu	Gowda	Chandra	Vellore	Talip
Masrani	Kodumudi	Gundlapalli	Chandrasekar	Venkataraman	Tanmaya
Matu	Kolar	Guntur	Channarayapatra	Venkateshwara	Tapas
Mayur	Konduru	Gurinder	Chatterji	Venugopal	Tarpa
Meenakshi	Koppale	Hament	Cheenu	Vidi	Tendulkar
Meher	Kota	Hazare	Chennapragada	Vidyasagar	Thamry
Melliyal	Krishnamma	Hiranandani	Chetana	Vijayalakshmi	Thirumalai
Michandani	Kulkarni	Hynala	Chiba	Vijaysaradhi	Thommana
Mirchandani	Kunal	Irani	Chinnappan	Vineeta	Thuraisingham
Mittur	Kurian	Jagder	Chittibabu	Vipperla	Tikekar
Moidu	Kuttikkad	Jandhyala	Choudhari	Virasana	Tirumalesa
Monica	Lahiri	Jasthi	Chudasama	Virmani	Trishwant
Mounil	Lalith	Jeeri	Daruka	Vishnavi	Tummala
Mukherjee	Lath	Jindal	Datta	Visvanathan	Tyagri
Mukund	Lecamwasam	Jonnalagadda	Desai	Vittal	Udipi
Munish	Luthra	Kaalki	Dhiri	Vraman	Ujwal
Murthy	Maddukuri	Kadowala	Diggavi	Yadavalli	Umrigar
Murugesan	Magesh	Kalirai	Dosanjh	Yamini	Uppalapati
Muthukrishn	Mahale	Kalpna	Duranjaya	Yashodhara	Uttanka
Naagesh	Mahatma	Kandadai	Ekachakra	Yegammai	Vaidheeswarran
Naeem	Majety	Kankipati	Engineer	Yeshonath	Vaish
Nagaraja	Makhija	Karapiet	Gaekwad	Zev	Vakil
Nageshwar	Malipeddi	Kasthurirangan	Gambhir	Ahsen	Vamshi
Nahid	Malti	Katragadda	Gangulee	Apte	Vaninadh
Naini	Manasi	Kedar	Gavaskar	Bai	Varati
Namrata	Mandava	Kenchammana	Ghorpade	Battacharjee	Varun
Nandita	Manesh	Kesiraju	Gidh	Bhanjee	Vasudev
Naran	Mangina	Kharbanda	Girsh	Bipen	Vattikota
Narayan	Manjari	Kirmani	Gopalakrishnan	Buhpathi	Vedavyasa
Naseer	Manmeet	Kodali	Gordha	Chandar	Veeraraju
Natterraja	Manushi	Koganti	Gowravaram	Chandrakala	Velusamy
Nayna	Marita	Konchady	Gundugollu	Chandrasekaran	Venkataramanan
Neelakantachar	Matanga	Konkar	Gunturu	Chapal	Venkateswaran
Neeru	Maudgalya	Koppula	Gurudutt	Chaudhari	Venugopalan
Nergis	Mayuri	Kothari	Harbir	Chella	Vidur
Nihar	Meenakshisundaram	Krithivas	Hemalatha	Cheran	Vidyashankar
Nikunj	Meherhomji	Kumawagra	Hiten	Chethan	Vijayanath
Nilu	Merchant	Kuntal	Ilango	Chidambaram	Vikriti
Niraj	Mihir	Kurtha	Iyer	Chippada	Vinit
Nirmala	Mista	Kutumbaka	Jahnavi	Chittoor	Vipul
Nishit	Mitul	Lalima	Janjua	Choudhary	Virat
Nitesha	Mokate	Lalji	Jayakar	Contractor	Visala
Niveda	Mooljee	Laul	Jeevan	Daryapurkar	Vishnuraman
Ogale	Mousumi	Lokhande	Jinen	Davuluri	Visvayu
Padmanabh	Mukhi	Macharla	Joshi	Dhadda	Vivatma
Pai	Mukunda	Madhabi	Kabir	Dhrtiman	Vuppula
Palia	Muniyappa	Mahabala	Kaikini	Dinath	Yadgiri
Palshikar	Murti	Mahankali	Kallakuri	Dravid	Yamni
Panick	Musunur	Mainak	Kambhampat	Durjaya	Yashovarman
Panth	Muthukrishnan	Maji	Kandathil	Eknath	Yellepeddy
Paramartha	Nabendu	Malhotra	Kanmani	Eswara	Yogendra
Parnita	Nagabhushana	Mallick	Karim	Gahlot	Agarkar
Parthiban	Nagarajan	Mamta	Kasturirangan	Ganapathiraman	Amroliwallah
Pasuma	Nageshwara	Manavi	Kaul	Ganguly	Baboor
Patterjee	Naidoo	Mandhatri	Kedarnath	Ghandi	Banker
Pavi	Nakul	Mangalvedhe	Keshab	Ghosal	Bhagwat
Pendyala	Nandakishore	Manikkalingam	Keskar	Gilab	Bhattacharya
Phadkar	Nandkeolyar	Manju	Khilnani	Godambe	Bonjani
Pillalamarri	Narang	Manohar	Kishen	Gopalan	Chakrabarti
Polamreddy	Narayanaswamy	Maqbool	Kodanda	Gorti	Chandiramani
Pooja	Nashier	Markendaya	Kola	Gridharan	Chandran
Prabhath	Naueshwara	Mathrubootham	Konda	Gunendran	Chandrashaker
Praharaj	Nayudu	Maya	Konkipudi	Gupte	Chaterju
Prasad	Neelam	Medapati	Koritala	Gutala	Chauhan
Prasanth	Neha	Megana	Kotla	Harishandra	Chellappan
Prasoon	Nerurkar	Mehta	Kriti	Himani	Chet
Praveenkumar	Niharika	Meyappan	Kumbla	Hitendra	Chhavvi
Premkumar	Nilani	Milind	Kunwarjit	Ilyas	Chinmay
Prithvi	Nilufar	Mitanu	Kurupath	Jadeja	Chitnis
Priyadarshi	Niral	Modi	Labhsha	Jai	Chivukula
Profulla	Nirupa	Mondem	Lalit	Jannavi	Chowdhury
Pulavarti	Nishita	More	Lanka	Jayantilal	Darisipudi
Punati	Nithin	Muddiah	Lavanis	Jeoomal	Datar
Punj	Nivedita	Muktheswara	Lolaksi	Jinturkar	Deivan
Purva	Omarjeet	Mukundan	Mackherdhuj	Joshipura	Dhatri
Pusti	Padmanabhan	Muppala	Madhana	Kabra	Dhurvasula
Rachna	Pal	Murty	Mahadeo	Kaisth	Divecha
Ragha	Pallavan	Muthiah	Mahanthapa	Kallianpur	Duleepsinhji
Raghuram	Pamela	Muthukumarasamy	Maiti	Kambhampati	Dwijen
Rajabhushan	Panjwani	Nachiketa	Majoo	Kandula	Emankum
Rajan	Panyala	Naganathan	Malik	Kansal	Gade
Rajashi	Parameswaran	Nagaswamy	Mallika	Karkada	Gajraj
Rakala	Partha	Nagi	Manandhar	Kateel	Ganeshwaran
Ramamani	Parul	Nailadi	Manchanda	Kaushal	Garlanka
Raman	Patachli	Nallamothu	Mandyam	Kedia	Ghei
Ramanujam	Pauravi	Nandedkar	Mangalwadi	Keshav	Ghoshdashtidar
Ramaswamy	Pavithran	Nanga	Maninder	Ketaki	Giridharan
Ramila	Pennathur	Narasimha	Manjunath	Khodabhai	Gokaraju
Ramprakash	Phadnis	Narmada	Manohari	Kishore	Gorantla
Ranadhir	Pillay	Natasha	Maran	Kodandarami	Gowd
Rangarajan	Polavarapu	Navya	Maruthi	Kolagunta	Gundamaraju
Ranjan	Poola	Neeharika	Mati	Kondapalli	Guntupalli
Rasiah	Prachi	Neena	Mayappan	Koothrappally	Gurijala
Raven	Prajapati	Neil	Medha	Kosanam	Hamada
Raviram	Prasai	Nidhi	Meghana	Koushika	Hattangady
Reema	Prasata	Nikhil	Mehul	Kudesia	Hinduja
Renukunta	Prassana	Nilima	Mhambrey	Kumble	Huggahilli
Richa	Pravil	Nimesh	Minakshi	Kuram	Innuganti
Rishmal	Prerana	Nirav	Mitra	Kuruvilla	Jagarlamudi
Roy	Prithviraj	Nisha	Mohaiemen	Laddha	Jana
Rudraraju	Priyadarshini	Nita	Mongia	Lalita	Jaspreet
Rustagi	Progyan	Nitin	Motala	Lata	Jayasurya
Sadalge	Puli	Nuguru	Mudhol	Lavanya	Jimuta
Saeed	Pundari	Omkar	Mukti	Lolla	Jobanputra
Sahar	Punnoose	Padmesh	Mulla	Macwan	Jyotiradha
Saidullah	Pusan	Palanirajan	Muqtedar	Madhani	Kadamuddi
Sajal	Pyara	Paloma	Murugan	Mahadevan	Kalanadhabhatla
Sakib	Rachoor	Pandian	Muthu	Mahapatra	Kalpak
Salim	Raghavanpillai	Pankajakshan	Muthupalaniappan	Maitreya	Kampan
Sameer	Raghuvir	Papa	Nadhamuni	Makam	Kanive
Samrat	Rajagopal	Paritosh	Nagappa	Malini	Kapoor
Sandip	Rajani	Parthasarathi	Nagedwaran	Mallikarjun	Kasavaraju
Sangameswar	Rajasimha	Pasapuleti	Nagin	Manas	Katka
Sanghi	Rakhi	Patankar	Naimesh	Manchapora	Kayeeda
Sankait	Ramamohan	Pavanaja	Namasri	Maneesh	Kelaka
Santanu	Ramana	Payal	Nandin	Mangesh	Keshaw
Sanyukta	Ramaprasad	Perumal	Naoomal	Manivanan	Khanderia
Sara	Ramchand	Phani	Narasimhan	Manjusha	Khursh
Saraswathi	Ramjee	Piyush	Narsi	Mansey	Kity
Sarin	Ramprakesh	Ponnada	Nath	Margasahayam	Koduri
Sarup	Ranadive	Potla	Nayak	Maruti	Kommana
Sasthi	Rangarathnam	Pradip	Neel	Matta	Koneru
Sathianarayan	Ranjana	Pramath	Neeraj	Mayekar	Koppolu
Satsangi	Rathiea	Prasanna	Nelagadde	Medikonda	Kothandaraman
Satyavrat	Ravikanth	Prashant	Nidra	Mehendale	Krishnamurthy
Savdeep	Ravuri	Pratima	Niki	Meka	Kumar
Seetamraju	Rege	Preeti	Nilini	Mhari	Kunderan
Selvam	Resham	Prisha	Nira	Mirajkar	Kurinji
Senapathy	Riddhi	Pritish	Nirguna	Mittal	Kutty
Seshadrinathan	Ritula	Priyavardhan	Nishar	Mohanty	Lakhani
Setra	Ruchi	Prudvi	Niten	Moni	Lalitha
Shahbaz	Rukmini	Pulkit	Nitu	Motiwala	Latha
Shailendra	Saandeep	Punita	Nukala	Mudigonda	Lokesh
Shally	Sadaram	Puranjay	Oruganti	Mukul	Luthria
Shanbhag	Sagar	Pushkar	Pahad	Multani	Madduri
Shashank	Sahgal	Rabinder	Palanisamy	Murli	Mageshkumar
Sheba	Saighiridhar	Radheshyam	Palomi	Murugappa	Mahalingam
Shilpa	Sajan	Raghavendran	Pandit	Muthukaruppan	Mahavira
Shirishkumar	Saklani	Ragunathan	Pankharia	Muthuswami	Majhi
Shivaprakash	Saloni	Rajah	Papatranal	Nadkarni	Malavika
Shradhdha	Samiksha	Rajarama	Parmar	Nagaraj	Malleshi
Shridhar	Samudra	Raje	Parthasarathy	Nagesh	Mamgain
Shrisha	Sandipa	Ramadin	Pashupathy	Nagpal	Manavendra
Shubhashish	Sangappa	Ramamurthy	Patel	Naimish	Mandayam
Shvetank	Sangita	Ramanand	Pavani	Namdev	Mangalampally
Simha	Sankaran	Ramasubraman	Pedapudi	Nandini	Manglorkar
Sitipala	Santhanakrishnan	Ramchandra	Perumbeti	Nara	Manjrekar
Sivasubramaniam	Sanzgiri	Ramkumar	Phutika	Narasinha	Mannem
Snigdha	Saraf	Ramsamooj	Poduri	Nartana	Manyam
Solanki	Sarat	Ranga	Ponnekanti	Nathan	Markandeya
Somayaji	Saripella	Rangnekar	Potluri	Nayar	Matangi
Sonia	Sarwate	Ranjini	Prafull	Neela	Mavalvala
Soumen	Saswata	Rathore	Pramila	Neerja	Mecca
Sourabh	Sathyanarayana	Ravipati	Prasannakumar	Nema	Meenan
Sree	Sattar	Raza	Prashanth	Nigam	Mehra
Sreekanthan	Satyen	Rema	Pratyush	Nikitha	Merchia
Sreevijayan	Sawalha	Revathi	Preetinder	Nilofer	Milan
Srikrishna	Seetharaman	Rima	Pritha	Niradhara	Mitali
Srini	Selvi	Robi	Privrata	Nirmal	Mitun
Srivastava	Senapati	Ruchir	Priyodarshi	Nisheeth	Mona
Sthanumurthy	Seshan	Rupa	Puja	Nitesh	Moorthy
Subbaratnam	Shaban	Sabeer	Pullela	Nitya-Sundara	Mrudaya
Subhuja	Shahid	Sadasivam	Punith	Nuregesan	Mukku
Subramanian	Shailesh	Saginala	Puri	Padmakant	Mukundagiri
Subudhi	Shameem	Sahni	Pushkarini	Pahwa	Munusamy
Sudarshan	Shantinath	Sailendra	Rabindra	Palathingal	Murtugudde
Sudeva	Shashidhar	Saji	Radhey	Pals	Muthanna
Sudheer	Shefali	Saldanha	Raghunandan	Pandya	Muthukumar
Sujeet	Shindi	Sambandam	Raguraman	Pant	Nachik
Sukhjinder	Shirvaikar	Samit	Rajal	Parag	Nagalingam
Sumanna	Shokrollahi	Sanaka	Rajaraman	Parnika	Nagarjuna
Sundaramoorthy	Shreekant	Sandy	Raji	Parthathy	Nageswar
Sunrita	Shriharsha	Sangeeta	Ramakan	Pasram	Naik
Surabhi	Shrivastava	Sanigepalli	Ramamurti	Pattabhiraman	Nalini
Surekha	Shubhendu	Sankrant	Ramanathan	Paveljit	Nandakumar
Suriyaprakash	Shyamsundar	Santharam	Ramasubramanian	Pendharkar	Nandy
Surujnarine	Sinduvalli	Sapna	Ramdas	Pewar	Narasimban
Suryanarayana	Sivakumar	Sarangarajan	Rammohan	Pichai	Narayanswami
Suthar	Sivasubramanian	Saravati	Ramsundar	Podury	Nasir
Swamy	Sobha	Sarmad	Ranganathan	Ponte	Navarathna
Sweta	Solkar	Sashekala	Rangwala	Prabhat	Nayyar
Talwar	Somendra	Sathasivam	Ranjitsinhji	Pragalsingh	Neelesh
Tantry	Sony	Satin	Ratnasabapathi	Pramsu	Nehru
Tapesh	Soumitra	Satyanarayana	Raviprakash	Prasanta	Nidheesh
Tarpana	Sourajyoti	Saunak	Reba	Prashun	Nikesh
Tetegni	Sreedevan	Sawardekar	Rengarajan	Praveen	Nilesh
Thandray	Sreenivas	Sekar	Revati	Preetish	Nimbalkar
Thirumalaiswamy	Sridevan	Sen	Rishi	Prithu	Niramitra
Thribhuvana	Srikrisna	Seri	Roopak	Priyabroto	Nirupama
Thuvaradran	Sripadam	Sethi	Ruchira	Probal	Nishtha
Tikku	Srivaths	Shachi	Rupali	Pujar	Niti
Toodi	Subas	Shail	Sachi	Pummy	Nizami
Trupti	Subbarayan	Shaje	Sadayappan	Punitha	Omesh
Tupil	Subodh	Shamshaard	Sagoo	Purujit	Padmasola
Ubriani	Subramanien	Shareeka	Sai	Puskara	Palam
Udit	Sucharita	Shashwat	Sailesh	Rabindran	Pallavi
Ulind	Sudarshana	Shibu	Sajid	Radia	Pancholi
Unmesh	Sudevi	Shinjinee	Saligrama	Raghunathan	Pankaj
Uppuluri	Sudhindranath	Shivaiah	Sambandan	Rai	Paola
Uttara	Sujeev	Shorey	Sammeta	Rajamani	Parantap
Vaidhyanathan	Suksma	Shreerang	Sanat	Rajarshi	Parthak
Sumedh	Shrinivas	Sangal	Raju	Parvin
Sundararajan	

);

foreach (uniq @names){
    print $_ . " ";
}
exit;
for (my $i = 0; $i < $n; $i++){
    chomp(my $word = <STDIN>);
    given ($word){
        when ($_ ~~ /east|west|north|south/i) {say "place"}
        when ($_ ~~ /africa|asia|america|euro/i) {say "place"}
        when (@names ~~ /$_/) {say "person"}
        when (@places ~~ /$_/) {say "place"}
        default {say "person"}
    }
}
