int g_emgBrake; // ρνmb`
int g_svcBrake; // νpΕεmb`
int g_brakeNotch; // u[Lmb`
int g_powerNotch; // Νsmb`
int g_reverser; // o[T
bool g_pilotlamp; // pCbgv
int g_time; // »έ
float g_speed; // ¬xvΜ¬x[km/h]
int g_deltaT; // t[Τ[ms/frame]
	//€³vΞ
int McKey; //}XRL[
int ini_UseJRTIMS; //JRTIMSgpΒΫ
int ini_UseUnit; //jbggpΒΫ
int ini_UseDistance; //s£gpΒΫ
int ini_Line; //ni5FΌA7FμkA9FηγcA13FsSj

TIMS_new_TMIni ini;

ATS_HANDLES g_output; // oΝ

#define ATS_BEACON_SPP 30 // βΤwΚίh~u
#define ATS_BEACON_NUM 150 // TIMSρΤΤ
#define ATS_BEACON_KIND 101 // TIMSρΤνΚ
#define ATS_BEACON_DIR 102 // TIMSisϋόέθ
#define ATS_BEACON_DIST 103 // TIMS£ΑZέθ
#define ATS_BEACON_APP 105 // TIMSwΪί
#define ATS_BEACON_NEXT 106 // TIMSwέθ
#define ATS_BEACON_NEXTTIME 107 // TIMSwέθ
#define ATS_BEACON_NEXTTRL 108 // TIMSwΤόέθ
#define ATS_BEACON_STA 110 // TIMSwΌ\¦
#define ATS_BEACON_ARV 111 // TIMS
#define ATS_BEACON_LEV 112 // TIMSo­
#define ATS_BEACON_TRL 113 // TIMSΤό
#define ATS_BEACON_LIM1 114 // TIMS§ΐ¬xIN
#define ATS_BEACON_LIM2 115 // TIMS§ΐ¬xOUT
#define ATS_BEACON_SPN 116 // TIMSwΤΤ

#define ATS_BEACON_LEG 104 // TIMS^sp^[
#define ATS_BEACON_FOR 109 // TIMSρΤsζ
#define ATS_BEACON_ARW 117 // TIMSsH\ξσ

#define ATS_BEACON_SUBA 118 //TIMSsH
#define ATS_BEACON_SUBL 119 //TIMSsH­
#define ATS_BEACON_SUBN 122 //TIMSsHρΤέθ
#define ATS_BEACON_SUBK 123 //TIMSsHνΚέθ

#define ATS_BEACON_LSA 124 //TIMSI_
#define ATS_BEACON_LSL 125 //TIMSI_o­
#define ATS_BEACON_LST 126 //TIMSI_Τό
#define ATS_BEACON_LSN 127 //TIMSsHI_wΌ

#define ATS_BEACON_BTSL 128 //TIMSΌOΜw
#define ATS_BEACON_ATSA 129 //TIMSΜw
#define ATS_BEACON_ATSL 130 //TIMSΜw­
#define ATS_BEACON_BTST 131 //TIMSΌOΜwΤό
#define ATS_BEACON_ATST 132 //TIMSΜwΤό
#define ATS_BEACON_BTSN 133 //TIMSΌOΜwwΌ
#define ATS_BEACON_ATSN 134 //TIMSΜwwΌ


#define TIMS_DECELERATION 19.5F // Έ¬θ (Έ¬x[km/h/s] x 7.2)
// 19.5=55^2/(180-25)
#define TIMS_OFFSET 0.5F // ΤγqItZbg[m]

#define RANDOMIZE_UNITTIMS 30 // TIMSjbg\¦ΜXVm¦
#define RANDOMIZE_UNITLAMP 10 // jbg\¦ΜXVm¦
#define UPDATE_SPAN 180000 // ^sξρXVΜΕαΤu
#define RELAY_REQUIREMENT 7.5f // sm[?μ·ι¬x

#define SPP_DECELERATION 19.5F // Έ¬θ (Έ¬x[km/h/s] x 7.2)
// 19.5=55^2/(180-25)
#define SPP_OFFSET 0.5F // ΤγqItZbg[m]
#define SPP_ALARMTYPE 1 // 0: JθΤ΅­Ή, 1; 1ρ­Ή
#pragma warning(disable: 4996)

class CTims
{
public:
	int EmergencyNotch; // ρνmb`
	int *BrakeNotch; // u[Lmb`
	int *PowerNotch; // Νsmb`
	int *Reverser; // o[T[
	int *Time; // »έ
	float *TrainSpeed; // ¬xvΜ¬x[km/h]
	int *DeltaT; // t[Τ[ms/frame]
	float BcPressure; // u[LV_³Ν[kPa]
	float MrPressure; // ³σC_³Ν[kPa]
	float Current; // d¬[A]
	double Location; // ρΤΚu[m]

	int Kind; // ρΤνΚ
	int Number[4]; // ρΤΤ(1000 - 100 - 10 - 1)
	int Charactor; // ρΤΤ(L)
	int From; // wΌ\¦(n­)
	int For; // wΌ\¦(ρΤsζ)
	int Destination; // wΌ\¦(sζ)
	int This; // wΌ\¦(©w)
	int Next; // wΌ\¦(w)
	int NextBlink; // wΌ\¦Μ_Ε
	int	NextBlinkLamp; // wβΤ 20190207ΗΑ
	int NextTime[3]; // (wA - ͺ - b)
	int NextTrack; // wΤό
	int Crawl; // sζΤ
	int CrawlLimit; // s¬x
	int AfterNumber[4]; // ^pρΤΤ(1000 - 100 - 10 - 1)
	int AfterChara; // ^pL
	int AfterTime[2][3]; // ^p­
	int AfterKind; //^pνΚ
	int TrainArrow; // sH\ξσ
	int Station[10]; // wΌ\¦
	int SESta[10]; //ΠόwΌ
	int SEDirection; //Πόisϋό
	int SEArea; //ΠόpsϋΚ
	int PassSta[10]; // ΚίwΌ\¦
	int Arrive[10][3]; // ( - ͺ - b)
	int Leave[10][3]; // o­( - ͺ - b)
	int Track[10]; // wΤό
	int Limit[10]; // Ε¬xIN
	int Limit2[10]; // Ε¬xOUT
	int Span[10][2]; // wΤsΤ
	int HiddenLine[10]; // XVΙ1sΈΒρ\¦Ι·ι
	int TrackPath[10]; // JΚξρ(100m²Ζ)
	int TrackPath2[120]; // JΚξρ(25m²Ζ)
	float StartingPoint; // £vZΜN_
	int Distance1000; // s£(kmΜ)
	int Distance100; // s£(100mΜ)
	int Distance10; // s£(10mΜ)
	int Location1000; // ρΤΚu(kmΜ)
	int Location100; // ρΤΚu(100mΜ)
	int Location10; // ρΤΚu(10mΜ)
	int TimsSpeed100; // TIMS¬x(100Μ)
	int TimsSpeed10; // TIMS¬x(10Μ)
	int TimsSpeed1; // TIMS¬x(1Μ)
	int UnitTims[10]; // TIMSjbg\¦(0-9)
	int UnitState[10]; // jbg\¦(0-9)
	int BrakeDelay; // u[Lwί
	int AccelDelay; // Νswί
	int BcCaution; // 200kPax
	int BcPressCut; // u[LΈ³·ι
	int RelayState; // sm[
	int Direction; // isϋό
	int ArrowDirection; // isϋόξσ
	int PassMode; // Κίέθ

	//dΤX^tpΗΑ
	int	Before; //ΌOΜw
	int	After; //Μw
	int	BeforeStationTime[3]; // ΌOΜw( - ͺ - b)
	int	AfterStationTimeA[3]; // Μw( - ͺ - b)
	int	AfterStationTimeL[3]; // Μw­Τ( - ͺ - b)
	int	BeforeTrack; // ΌOΜwΤό
	int	AfterTrack; // ΜwΤό
	int LastStopTime[3]; // I_( - ͺ - b)
	int LastStopTimeL[3]; // I_o­( - ͺ - b)
	int LastStopTrack; // I_Τό
	int RelayName; // sHI_wΌ


	int Speed; // ¬xv
	int Speed100; // ¬x(100Μ)
	int Speed10; // ¬x(10Μ)
	int Speed1; // ¬x(1Μ)
	int BcPress0; // u[LV_wj(0-180kPa)
	int BcPress1; // u[LV_wj(200-380kPa)
	int BcPress2; // u[LV_wj(400-580kPa)
	int BcPress3; // u[LV_wj(600-780kPa)

	int BcPress4; // u[LV_l(100Κ)
	int BcPress5; // u[LV_l(10Κ)
	int BcPress6; // u[LV_l(1Κ)
	int BcPress7; // u[LV_wj(int^)

	int MrPress0; // ³σC_wj(750-795kPa)
	int MrPress1; // ³σC_wj(800-845kPa)
	int MrPress2; // ³σC_wj(850-895kPa)

	int MrPress4; // ³σC_l(100Κ)
	int MrPress5; // ³σC_l(10Κ)
	int MrPress6; // ³σC_l(1Κ)
	int MrPress7; // ³σC_wj(int^)

	int Ammeter0; // d¬v
	int Ammeter1; // d¬v1000Κ
	int Ammeter2; // d¬v100Κ
	int Ammeter3; // d¬v10Κ
	int Ammeter4; // d¬v1Κ
	int AmmeterC; // d¬v

	int AccelCutting; // Νsx(±ΜάΕ½f΅Θ’)

	int RelayD; // sm[
	int LbInit; // ρN?f¬νΉ
	int AirHigh; // ρνu[LΙπΉ
	int AirApply; // u[LΈ³Ή
	int EmgAnnounce; // ρνu[Lϊ
	int AirApplyEmg; // u[LΈ³Ή(ρν)
	int UpdateInfo; // ^sξρXV


	// πΌΨΦ
	int AC; // π¬
	int DC; // Ό¬
	int CVacc; // §δd³Ων
	int CVacc10; // §δd³(10Κ)
	int CVacc1; // §δd³(1Κ)
	int ACacc; // π¬d³Ων
	int ACacc10000; // π¬d³(10000Κ)
	int ACacc1000; // π¬d³(1000Κ)
	int ACacc100; // π¬d³(100Κ)
	int DCacc; // Ό¬d³Ων
	int DCacc1000; // Ό¬d³(1000Κ)
	int DCacc100; // Ό¬d³(100Κ)
	int DCacc10; // Ό¬d³(10Κ)
	int Cvmeter; // §δwj
	int Acmeter; // π¬wj
	int Dcmeter; // Ό¬wj
	int Accident; // Μ
	int Tp; // O
	int VCB_ON; // VCBSό
	int VCB_OFF; // VCBSΨ
	int VCB; // VCB
	int tmr_ACDC;
	int step_ACDC;
	int alert_ACDC;

	// INIt@C©ηέθ
	int ini_cutPressTime; // u[L³πΈ³·ιΤ
	int event_lbInit; // ρN?Νsx

	void load(void)
	{
		Kind = 0; // ρΤνΚ
		Charactor = 0; // ρΤΤ(L)
		From = 0; // wΌ\¦(n­)
		For = 0; // wΌ\¦(ρΤsζ)
		Destination = 0; // wΌ\¦(sζ)
		This = 0; // wΌ\¦(©w)
		Next = 0; // wΌ\¦(w)
		NextBlink = 0; // wΌ\¦Μ_Ε
		NextBlinkLamp = 0; // wβΤ 20190207ΗΑ
		NextTrack = 0; // wΤό
		Crawl = 0; // sζΤ
		CrawlLimit = 0; // s¬x
		AfterChara = 0; // ^pL
		LastStopTrack = 0; // I_Τό
		RelayName = 0; // sHI_wΌ
		TrainArrow = 0; // sH\ξσ

		m_dist = 0; // β~\θ_£

		m_pushUpFlag = -1; // \¦XVΜtO
		m_pushUpBeacon = 0; // \¦XVΜnγq
		m_pushUpCount = 0; // \¦XVΜJθΤ΅
		m_tmrVisible = *Time; // j^ΜXebvXV

		m_thisName = 0; // ©wΌ
		m_nextName = 0; // wΌ
		m_nextTrack = 0; // wΤό

		m_pathStaDist = 0; // JΚξρΜwΚuξρ

		m_distance = 0; // s£
		m_direction = 1; // £ΈZΜ»θ
		m_distDef = 0; // ρΤΚuΜβ³

		ResetArray(); // zρΜϊ»
		// PushNext(); // wπΕVΙ·ι
		// Receive(0); // e[uπXV·ι

		StartingPoint = 0.0f; // £vZΜN_
		Distance1000 = 0; // s£(kmΜ)
		Distance100 = 10; // s£(100mΜ)
		Distance10 = 10; // s£(10mΜ)
		Location1000 = 0; // ρΤΚu(kmΜ)
		Location100 = 10; // ρΤΚu(100mΜ)
		Location10 = 10; // ρΤΚu(10mΜ)

		TimsSpeed100 = 0; // TIMS¬x(100Μ)
		TimsSpeed10 = 0; // TIMS¬x(10Μ)
		TimsSpeed1 = 10; // TIMS¬x(1Μ)

		BrakeDelay = 0; // u[Lwί
		AccelDelay = 0; // Νswί
		BcCaution = 0; // 200kPax
		BcPressCut = 0; // u[LΈ³·ι
		RelayState = 0; // sm[
		Direction = 0; // isϋό
		ArrowDirection = 0; // isϋόξσ
		PassMode = 0; // Κίέθ

		Before = 0; //ΌOΜw
		After = 0; //Μw
		BeforeTrack = 0; // ΌOΜwΤό
		AfterTrack = 0; // ΜwΤό

		SEDirection = 1; //Πόpisϋό
		SEArea = 0; //ΠόpsϋΚ

		Speed = 0; // ¬xv
		Speed100 = 10; // ¬x(100Μ)
		Speed10 = 10; // ¬x(10Μ)
		Speed1 = 0; // ¬x(1Μ)
		BcPress0 = 10; // u[LV_wj(0-180kPa)
		BcPress1 = 10; // u[LV_wj(200-380kPa)
		BcPress2 = 10; // u[LV_wj(400-580kPa)
		BcPress3 = 10; // u[LV_wj(600-780kPa)
		BcPress4 = 10; // u[LV_wj(100Κ)
		BcPress5 = 10; // u[LV_wj(10Κ)
		BcPress6 = 0; // u[LV_wj(1Κ)
		BcPress7 = 0; // u[LV_wj(int)

		MrPress0 = 10; // ³σC_wj(750-795kPa)
		MrPress1 = 10; // ³σC_wj(800-845kPa)
		MrPress2 = 10; // ³σC_wj(850-895kPa)
		MrPress4 = 10; // ³σC_wj(100Κ)
		MrPress5 = 10; // ³σC_wj(10Κ)
		MrPress6 = 0; // ³σC_wj(1Κ)
		MrPress7 = 0; // ³σC_wj(int)

		Ammeter0 = 0; // d¬v

		Ammeter1 = 0; // d¬v1000Κ
		Ammeter2 = 0; // d¬v100Κ
		Ammeter3 = 0; // d¬v10Κ
		Ammeter4 = 0; // d¬v1Κ
		AmmeterC = 10; // d¬v

		AccelCutting = 0; // Νsx

		m_tmrBcPressCut = 0; // u[LΈ³Μ^C}[

		m_relayD = ATS_SOUND_STOP; // sm[
		m_lbInit = ATS_SOUND_STOP; // ρN?f¬νΉ
		m_airHigh = ATS_SOUND_STOP; // ρνu[LΙπΉ
		AirApply = ATS_SOUND_STOP; // u[LΈ³Ή
		m_bcPrsDelta = 0.0F; // u[LV_³Ν[kPa]
		m_emgAnnounce = ATS_SOUND_STOP; // ρνu[Lϊ
		m_airApplyEmg = ATS_SOUND_STOP; // u[LΈ³Ή(ρν)
		m_updateInfo = ATS_SOUND_STOP; // ^sξρXV
		m_deltaUpdate = *Time - UPDATE_SPAN; // Oρ^sξρXV

		// πΌΨΦ
		AC = 0; // π¬
		DC = 1; // Ό¬
		CVacc = 0; // §δd³Ων
		CVacc10 = 10; // §δd³(10Κ)
		CVacc1 = 10; // §δd³(1Κ)
		ACacc = 0; // π¬d³Ων
		ACacc10000 = 10; // π¬d³(10000Κ)
		ACacc1000 = 10; // π¬d³(1000Κ)
		ACacc100 = 10; // π¬d³(100Κ)
		DCacc = 0; // Ό¬d³Ων
		DCacc1000 = 10; // Ό¬d³(1000Κ)
		DCacc100 = 10; // Ό¬d³(100Κ)
		DCacc10 = 10; // Ό¬d³(10Κ)
		Cvmeter = 100; // §δwj
		Acmeter = 0; // π¬wj
		Dcmeter = 1600; // Ό¬wj
		Accident = 0; // Μ
		Tp = 0; // O
		VCB_ON = 1; // VCBSό
		VCB_OFF = 0; // VCBSΨ
		VCB = 1; // VCB
		tmr_ACDC = *Time;
		step_ACDC = 3;
		alert_ACDC = 0;
	}

	void initialize(void)
	{
	}

	void execute(void)
	{
		// t[
		float speed = fabsf(*TrainSpeed); // ¬xΜβΞl[km/h]
		float def = speed / 3600 * *DeltaT; // 1t[Ε?’½£(βΞl)[m]
		float def2 = *TrainSpeed / 3600 * *DeltaT; // 1t[Ε?’½£(Ξl)[m]
		m_dist -= def; // cθ£πΈZ·ι

		// πΌΨΦ
		int temp_time = *Time - tmr_ACDC;
		switch(step_ACDC)
		{
		case 0: // Ό¬¨VCBΨ
			VCB_OFF = 1;
			VCB_ON = 0;
			VCB = 2;
			
			if(temp_time > 250)
			{
				Accident = 1; // Μ
			}
			if(temp_time > 500)
			{
				DCacc = 1; // Ό¬d³Ων
				DCacc1000 = 10; // Ό¬d³(1000Κ)
				DCacc100 = 10; // Ό¬d³(100Κ)
				DCacc10 = 10; // Ό¬d³(10Κ)
				Dcmeter = 0; // Ό¬wj
			}
			if(temp_time > 750)
			{
				CVacc = 1; // §δd³Ων
				Cvmeter = 83; // §δwj
				CVacc10 = 8; // §δd³(10Κ)
				CVacc1 = 3; // §δd³(1Κ)
			}
			if(temp_time > 1000)
			{
				Tp = 1; // O
			}
			break;
		case 1: // ³dζΤ
			VCB_OFF = 0;
			VCB_ON = 0;
			VCB = 0;

			AC = 0;
			DC = 0;
			ACacc = 0; // π¬d³Ων
			ACacc10000 = 10; // π¬d³(10000Κ)
			ACacc1000 = 10; // π¬d³(1000Κ)
			ACacc100 = 10; // π¬d³(100Κ)
			DCacc = 0; // Ό¬d³Ων
			DCacc1000 = 10; // Ό¬d³(1000Κ)
			DCacc100 = 10; // Ό¬d³(100Κ)
			DCacc10 = 10; // Ό¬d³(10Κ)
			Acmeter = 0; // π¬wj
			Dcmeter = 0; // Ό¬wj
			break;
		case 2: // ACLdζΤ
			VCB_OFF = 0;
			VCB_ON = 1;
			VCB = 1;

			DC = 0;
			DCacc = 0; // Ό¬d³Ων
			DCacc1000 = 10; // Ό¬d³(1000Κ)
			DCacc100 = 10; // Ό¬d³(100Κ)
			DCacc10 = 10; // Ό¬d³(10Κ)
			Dcmeter = 0; // Ό¬wj

			AC = 1;
			if(temp_time > 500)
			{
				ACacc = 1; // π¬d³Ων
				ACacc10000 = 10; // π¬d³(10000Κ)
				ACacc1000 = 2; // π¬d³(1000Κ)
				ACacc100 = 2; // π¬d³(100Κ)
				Acmeter = 220; // π¬wj
			}
			if(temp_time > 1000)
			{
				ACacc = 1; // π¬d³Ων
				ACacc10000 = 1; // π¬d³(10000Κ)
				ACacc1000 = 1; // π¬d³(1000Κ)
				ACacc100 = 2; // π¬d³(100Κ)
				Acmeter = 11200; // π¬wj
			}
			if(temp_time > 2000)
			{
				ACacc = 0; // π¬d³Ων
				ACacc10000 = 10; // π¬d³(10000Κ)
				ACacc1000 = 10; // π¬d³(1000Κ)
				ACacc100 = 10; // π¬d³(100Κ)
				Acmeter = 15500; // π¬wj
			}
			if(temp_time > 3000)
			{
				ACacc = 0; // π¬d³Ων
				ACacc10000 = 10; // π¬d³(10000Κ)
				ACacc1000 = 10; // π¬d³(1000Κ)
				ACacc100 = 10; // π¬d³(100Κ)
				Acmeter = 18000; // π¬wj
			}
			if(temp_time > 4000)
			{
				ACacc = 0; // π¬d³Ων
				ACacc10000 = 10; // π¬d³(10000Κ)
				ACacc1000 = 10; // π¬d³(1000Κ)
				ACacc100 = 10; // π¬d³(100Κ)
				Acmeter = 20000; // π¬wj
			}
			if(temp_time > 5000)
			{
				ACacc = 0; // π¬d³Ων
				ACacc10000 = 10; // π¬d³(10000Κ)
				ACacc1000 = 10; // π¬d³(1000Κ)
				ACacc100 = 10; // π¬d³(100Κ)
				Acmeter = 22000; // π¬wj
			}
			if(temp_time > 8000)
			{
				Accident = 0; // Μ
			}
			if(temp_time > 12000)
			{
				Tp = 0; // O
			}
			if(temp_time > 13000)
			{
				CVacc = 0; // §δd³Ων
				CVacc10 = 10; // §δd³(10Κ)
				CVacc1 = 10; // §δd³(1Κ)
				Cvmeter = 100; // §δwj
			}
			break;
		case 3: // DCLdζΤ
			VCB_OFF = 0;
			VCB_ON = 1;
			VCB = 1;
			
			AC = 0;
			ACacc = 0; // π¬d³Ων
			ACacc10000 = 10; // π¬d³(10000Κ)
			ACacc1000 = 10; // π¬d³(1000Κ)
			ACacc100 = 10; // π¬d³(100Κ)
			Acmeter = 0; // π¬wj
			
			DC = 1;
			if(temp_time > 500)
			{
				DCacc = 1; // Ό¬d³Ων
				DCacc1000 = 10; // Ό¬d³(1000Κ)
				DCacc100 = 1; // Ό¬d³(100Κ)
				DCacc10 = 8; // Ό¬d³(10Κ)
				Dcmeter = 180; // Ό¬wj
			}
			if(temp_time > 1000)
			{
				DCacc = 1; // Ό¬d³Ων
				DCacc1000 = 10; // Ό¬d³(1000Κ)
				DCacc100 = 7; // Ό¬d³(100Κ)
				DCacc10 = 4; // Ό¬d³(10Κ)
				Dcmeter = 740; // Ό¬wj
			}
			if(temp_time > 2000)
			{
				DCacc = 0; // Ό¬d³Ων
				DCacc1000 = 10; // Ό¬d³(1000Κ)
				DCacc100 = 10; // Ό¬d³(100Κ)
				DCacc10 = 10; // Ό¬d³(10Κ)
				Dcmeter = 1380; // Ό¬wj
			}
			if(temp_time > 3000)
			{
				DCacc = 0; // Ό¬d³Ων
				DCacc1000 = 10; // Ό¬d³(1000Κ)
				DCacc100 = 10; // Ό¬d³(100Κ)
				DCacc10 = 10; // Ό¬d³(10Κ)
				Dcmeter = 1500; // Ό¬wj
			}
			if(temp_time > 4000)
			{
				DCacc = 0; // π¬d³Ων
				DCacc1000 = 10; // Ό¬d³(1000Κ)
				DCacc100 = 10; // Ό¬d³(100Κ)
				DCacc10 = 10; // Ό¬d³(10Κ)
				Dcmeter = 1600; // Ό¬wj
			}
			if(temp_time > 7000)
			{
				Accident = 0; // Μ
			}
			if(temp_time > 11000)
			{
				Tp = 0; // O
			}
			if(temp_time > 12000)
			{
				CVacc = 0; // §δd³Ων
				CVacc10 = 10; // §δd³(10Κ)
				CVacc1 = 10; // §δd³(1Κ)
				Cvmeter = 100; // §δwj
			}
			break;
		case 4: // π¬¨VCBΨ
			VCB_OFF = 1;
			VCB_ON = 0;
			VCB = 2;
			
			if(temp_time > 250)
			{
				Accident = 1; // Μ
			}
			if(temp_time > 500)
			{
				ACacc = 1; // π¬d³Ων
				ACacc10000 = 10; // π¬d³(10000Κ)
				ACacc1000 = 10; // π¬d³(1000Κ)
				ACacc100 = 10; // π¬d³(100Κ)
				Acmeter = 0; // π¬wj
			}
			if(temp_time > 750)
			{
				CVacc = 1; // §δd³Ων
				Cvmeter = 83; // §δwj
				CVacc10 = 8; // §δd³(10Κ)
				CVacc1 = 3; // §δd³(1Κ)
			}
			if(temp_time > 1000)
			{
				Tp = 1; // O
			}
			break;
		}

		// ρN?Νsx
		if(event_lbInit > 0 && *PowerNotch > 0)
		{
			event_lbInit = 0;
			AccelCutting = *Time + 500;
			m_lbInit = ATS_SOUND_PLAY;
		}

		// ρN?f¬νΉ
		LbInit = m_lbInit;
		m_lbInit = ATS_SOUND_CONTINUE;

		// u[LΈ³
		if(m_tmrBcPressCut < *Time)
		{
			BcPressCut = 0;
			m_tmrBcPressCut = 0;
		}
		else
		{
			BcPressCut = 1;
		}

		//Ιπx^C}[Μhμ
		if(speed > 3.0f)
		{
			m_tmrBcPressCut = 0;
			BcPressCut = 0;
		}

		// sm[
		if(RelayState == 0 && speed >= RELAY_REQUIREMENT)
		{
			RelayState = 1;
			m_relayD = ATS_SOUND_PLAY;
		}
		else if(RelayState == 1 && speed <= RELAY_REQUIREMENT)
		{
			RelayState = 0;
			m_relayD = ATS_SOUND_PLAY;
		}

		RelayD = m_relayD;
		m_relayD = ATS_SOUND_CONTINUE;

		// ρνu[LΙπΉ
		AirHigh = m_airHigh;
		m_airHigh = ATS_SOUND_CONTINUE;

		// u[LΈ³Ή
		if(*BrakeNotch > 0 && BcPressure > 40.0F && BcPressure > m_bcPrsDelta)
		{
			AirApply = ATS_SOUND_PLAYLOOPING;
		}
		else
		{
			AirApply = ATS_SOUND_STOP;
		}

		m_bcPrsDelta = BcPressure; // u[LV_³Ν[kPa]

		// ρνu[Lϊ
		EmgAnnounce = m_emgAnnounce;
		m_emgAnnounce = ATS_SOUND_CONTINUE;

		// u[LΈ³Ή(ρν)
		AirApplyEmg = m_airApplyEmg;
		m_airApplyEmg = ATS_SOUND_CONTINUE;

		// ^sξρXV
		if(*TrainSpeed > 10.0f && *Time > m_deltaUpdate + UPDATE_SPAN)
		{
			m_deltaUpdate = *Time;

			if(rand()%200 == 0)
			{
				m_updateInfo = ATS_SOUND_PLAY;
			}
		}

		UpdateInfo = m_updateInfo; // ^sξρXV
		m_updateInfo = ATS_SOUND_CONTINUE;

		//wΌΜ}ό
		for (int i = 0; i < 7; i++)
		{
			if (SEDirection == 1) //ccAόA¬c}Ίθ
			{
				switch (SESta[i])
				{
				case 56: //k»£
					SESta[i + 1] = 101;
					break;
				case 101:
					SESta[i + 1] = 57;
					break;
				case 58: //kηZ
					SESta[i + 1] = 102;
					break;
				case 102:
					SESta[i + 1] = 59;
					break;
				case 62: //ͺΓ
					SESta[i + 1] = 103;
					break;
				case 103:
					SESta[i + 1] = 63;
					break;
				case 64: //Vδm
					SESta[i + 1] = 104;
					break;
				case 104:
					SESta[i + 1] = 65;
					break;
				case 67: //ϊδJ
					SESta[i + 1] = 105;
					break;
				case 105:
					SESta[i + 1] = 68;
					break;
				case 68: //ΰPΦ
					SESta[i + 1] = 106;
					break;
				case 106:
					SESta[i + 1] = 69;
					break;
				case 71: //TΨβ
					SESta[i + 1] = 107;
					break;
				case 107:
					SESta[i + 1] = 72;
					break;
				case 73: //Ύ‘_{
					SESta[i + 1] = 108;
					break;
				case 108: //φ€ό
					SESta[i + 1] = 74;
					break;
				case 74: //γXΨφ
					SESta[i + 1] = 31;
					break;
				case 49: //VSu
					SESta[i + 1] = SEArea == 1 ? 93 : 50;
					break;
				case 53: //¬c
					SESta[i + 1] = 13;
					break;
				case 13: //Νεμ
					SESta[i + 1] = SEArea == 2 ? 12 : 75;
					break;
				case 12:
				case 11:
				case 10:
				case 9:
				case 8:
				case 7:
				case 6:
				case 5:
				case 4:
				case 3:
				case 2:
					SESta[i + 1] = SESta[i] - 1;//]mόΚν
					break;
				case 1: //‘ς{¬
					SESta[i + 1] = 91;
					break;
				default:
					SESta[i + 1] = SESta[i] + 1;//Κν
					break;
				}
			}
			else //ccBόA¬c}γθ
			{
				switch (SESta[i])
				{
				case 57: //»£
					SESta[i + 1] = 101;
					break;
				case 101:
					SESta[i + 1] = 56;
					break;
				case 59: //¬?
					SESta[i + 1] = 102;
					break;
				case 102:
					SESta[i + 1] = 58;
					break;
				case 63: //
					SESta[i + 1] = 103;
					break;
				case 103:
					SESta[i + 1] = 62;
					break;
				case 65: //εθ¬
					SESta[i + 1] = 104;
					break;
				case 104:
					SESta[i + 1] = 64;
					break;
				case 68: //ΰPΦ
					SESta[i + 1] = 105;
					break;
				case 105:
					SESta[i + 1] = 67;
					break;
				case 69: //οc°O
					SESta[i + 1] = 106;
					break;
				case 106:
					SESta[i + 1] = 68;
					break;
				case 72: //\QΉ
					SESta[i + 1] = 107;
					break;
				case 107:
					SESta[i + 1] = 71;
					break;
				case 74: //γXΨφ
					SESta[i + 1] = 108;
					break;
				case 108: //φ€ό
					SESta[i + 1] = 73;
					break;
				case 31: //γXΨγ΄
					SESta[i + 1] = SEArea == 0 ? 74 : 30;
					break;
				case 93: //άδ
					SESta[i + 1] = 49;
					break;
				case 75: //¬c}Ν΄
					SESta[i + 1] = 13;
					break;
				case 13: //Νεμ
					SESta[i + 1] = 53;
					break;
				case 12:
				case 11:
				case 10:
				case 9:
				case 8:
				case 7:
				case 6:
				case 5:
				case 4:
				case 3:
				case 2:
				case 1:
					SESta[i + 1] = SESta[i] + 1;//]mόΚν
					break;
				case 91: //‘ς
					SESta[i + 1] = 1;
					break;
				default:
					SESta[i + 1] = SESta[i] - 1;//Κν
					break;
				}

			}
		}

		// wπ_Ε³Ήι
		if(speed * speed / TIMS_DECELERATION >= m_dist - 50 && m_dist > 0 && !m_blinking) // ¬xΖΈ (p^[)
		{
			m_blinking = true;

			if(m_pushUpFlag == 1) // βΤwΜΖ«
			{
				m_pushUpFlag = 2;
			}
		}

		// wΌ\¦Μ_Ε
		NextBlink = m_pushUpFlag == 2 ? ((*Time % 750) / 375) : 1;
		//20190207bθΗΑ
		NextBlinkLamp = m_pushUpFlag == 2 ? 1 : 0;

		// JΚξρ25m²Ζ(0³\¦A1’JΚζΤA2β~«E1A3β~«E2A4β~«E3A5β~«E4A6JΚζΤ1A7JΚζΤ2A8wζΤ1A9wζΤ2)
		for(int initPath2=0;initPath2<120;initPath2++)
		{
			// JΚζΤΜ\¦(Βό)
			TrackPath2[initPath2] = 6;
		}

		// JΚξρΜwΚuξρ
		m_pathStaDist -= def2; // cθ£πΈZ·ι

		if(m_pathStaDist > 0)
		{
			int pathStaDistfabsf25 = (int)fabsf(m_pathStaDist) / 25;

			// wζΤΜ\¦(Ύ’Βό)
			if(TrackPath2[pathStaDistfabsf25] >= 6){TrackPath2[pathStaDistfabsf25] = 8;}
			if(TrackPath2[pathStaDistfabsf25 - 1] >= 6){TrackPath2[pathStaDistfabsf25 - 1] = 8;}
			if(TrackPath2[pathStaDistfabsf25 - 2] >= 6){TrackPath2[pathStaDistfabsf25 - 2] = 9;}
			if(TrackPath2[pathStaDistfabsf25 - 3] >= 6){TrackPath2[pathStaDistfabsf25 - 3] = 8;}
			if(TrackPath2[pathStaDistfabsf25 - 4] >= 6){TrackPath2[pathStaDistfabsf25 - 4] = 8;}
			if(TrackPath2[pathStaDistfabsf25 - 5] >= 6){TrackPath2[pathStaDistfabsf25 - 5] = 9;}
			if(TrackPath2[pathStaDistfabsf25 - 6] >= 6){TrackPath2[pathStaDistfabsf25 - 6] = 8;}
			if(TrackPath2[pathStaDistfabsf25 - 7] >= 6){TrackPath2[pathStaDistfabsf25 - 7] = 8;}
			if(TrackPath2[pathStaDistfabsf25 - 8] >= 6){TrackPath2[pathStaDistfabsf25 - 8] = 8;}
		}

		// JΚξρΜΒ»­ξρ
		for(int i=0;i<10;i++)
		{
			// cθ£πΈZ·ι
			m_pathSecDist[i] -= def2;
			m_passSecLine[i] -= def2;

			// Β»­ζΨθόΜ\¦
			if(m_passSecLine[i] > 0)
			{
				int passSecLinefabsf25 = (int)fabsf(m_passSecLine[i]) / 25; // ζΨθόπόκ½’n_

				if(TrackPath2[passSecLinefabsf25] == 6){TrackPath2[passSecLinefabsf25] = 7;} // JΚζΤ1ΘηζΨθόπόκι
			}

			// sΐEΜ\¦
			if(m_pathSecDist[i] > 0)
			{
				int pathSecDistfabsf25 = (int)fabsf(m_pathSecDist[i]) / 25; // sΕ«ιΐEΜn_
				TrackPath2[pathSecDistfabsf25] = 5; // β~ΐEΜ\¦(Τ’Op`)
				TrackPath2[pathSecDistfabsf25 + 1] = 4; // β~ΐEΜ\¦(Τ’Op`)
				TrackPath2[pathSecDistfabsf25 + 2] = 3; // β~ΐEΜ\¦(Τ’Op`)
				TrackPath2[pathSecDistfabsf25 + 3] = 2; // β~ΐEΜ\¦(Τ’Op`)

				for(int pathNone2=pathSecDistfabsf25+4;pathNone2<120;pathNone2++)
				{
					TrackPath2[pathNone2] = 1; // ’JΚζΤΜ\¦(ό)
				}
			}
		}

		// OXRbNsbg
		m_tmrUpdate -= abs(*DeltaT); // t[ΈZ
		if(m_tmrUpdate < 0) // || *TrainSpeed == 0) // XV·ι
		{
			Speed = fabs(*TrainSpeed);
			Speed100 = fabs(*TrainSpeed) / 100;
			Speed10 = (fabs(*TrainSpeed) / 10) - (Speed100 * 10);
			Speed1 = fabs(*TrainSpeed) - (Speed100 * 100 + Speed10 * 10);

			if(*TrainSpeed < 1000 && Speed100 == 0){Speed100 = 10;}
			if(*TrainSpeed < 100 && Speed10 == 0){Speed10 = 10;}

			BrakeDelay = *BrakeNotch; // u[Lwί
			AccelDelay = *PowerNotch; // Νswί
			BcCaution = BcPressure < 200 && !m_door; // 200kPax

			BcPress0 = 10; // u[LV_wj(0-180kPa)
			BcPress1 = 10; // u[LV_wj(200-380kPa)
			BcPress2 = 10; // u[LV_wj(400-580kPa)
			BcPress3 = 10; // u[LV_wj(600-780kPa)
			MrPress0 = 10; // ³σC_wj(700-790kPa)
			MrPress1 = 10; // ³σC_wj(800-890kPa)
			MrPress2 = 10; // ³σC_wj(900-990kPa)

			if(BcPressure < 200){BcPress0 = BcPressure / 20;} // u[LV_wj(0-180kPa)
			else if(BcPressure < 400){BcPress1 = (BcPressure - 200) / 20;} // u[LV_wj(200-380kPa)
			else if(BcPressure < 600){BcPress2 = (BcPressure - 400) / 20;} // u[LV_wj(400-580kPa)
			else if(BcPressure < 800){BcPress3 = (BcPressure - 600) / 20;} // u[LV_wj(600-780kPa)

			if(MrPressure <= 750){MrPress0 = 10;} // 750kPaΘΊ
			else if(MrPressure > 750 && MrPressure < 795){MrPress0 = (MrPressure - 750) / 5;} // ³σC_wj(750-795kPa)
			else if(MrPressure < 845){MrPress1 = (MrPressure - 800) / 5;} // ³σC_wj(800-845kPa)
			else if(MrPressure < 895){MrPress2 = (MrPressure - 850) / 5;} // ³σC_wj(850-895kPa)

			//\¦//
			
			BcPress4 = fabs(BcPressure) / 100;
			BcPress5 = (fabs(BcPressure) / 10) - (BcPress4 * 10);
			BcPress6 = fabs(BcPressure) - (BcPress4 * 100 + BcPress5 * 10);

			BcPress7= fabs(BcPressure);

			if(BcPressure < 1000 && BcPress4 == 0){BcPress4 = 10;}
			if(BcPressure < 100 && BcPress5 == 0){BcPress5 = 10;}

			MrPress4 = fabs(MrPressure) / 100;
			MrPress5 = (fabs(MrPressure) / 10) - (MrPress4 * 10);
			MrPress6 = fabs(MrPressure) - (MrPress4 * 100 + MrPress5 * 10);

			MrPress7 = fabs(MrPressure);

			if(BcPressure < 1000 && BcPress4 == 0){BcPress4 = 10;}
			if(BcPressure < 100 && BcPress5 == 0){BcPress5 = 10;}
			//\¦±±άΕ

			Ammeter0 = fabs(Current); // d¬v

			Ammeter1 = fabs(Current) / 1000;
			Ammeter2 = (fabs(Current) / 100) - (Ammeter1 * 10);
			Ammeter3 = (fabs(Current) - (Ammeter1 * 1000 + Ammeter2 * 100)) / 10;
			Ammeter4 = (fabs(Current) - (Ammeter1 * 1000 + Ammeter2 * 100 + Ammeter3 * 10));

			if(Current < 1000 && Ammeter2 == 0){Ammeter2 = 10;}
			if(Current < 100 && Ammeter3 == 0){Ammeter3 = 10;}
			if(Current < 10 && Ammeter4 == 0){Ammeter4 = 10;}

			if(Current >= 0){AmmeterC = 10;}
			if(Current < 0){AmmeterC = 12;}

			m_tmrUpdate = 200 + (*Time % 50) * 5;
		}

		// Ej^[¬xv
		// m_distance += (def2 / 10) * m_direction; // t[ΈZ
		m_tmrTims -= abs(*DeltaT); // t[ΈZ
		if(m_tmrTims < 0) // || *TrainSpeed == 0) // XV·ι
		{
			// double temp_distance = m_distance + (fabs(StartingPoint - Location) * m_direction / 10);
			double temp_distance = ((Location / 10) - (StartingPoint / 10) * m_direction) + m_distance;
			
			Distance1000 = temp_distance / 100; // s£(kmΜ)
			Distance100 = (temp_distance / 10) - (Distance1000 * 10); // s£(100mΜ)
			Distance10 = temp_distance - (Distance1000 * 100 + Distance100 * 10); // s£(10mΜ)
/*
			Distance1000 = fabs(m_distance) / 100; // s£(kmΜ)
			Distance100 = (fabs(m_distance) / 10) - (Distance1000 * 10); // s£(100mΜ)
			Distance10 = fabs(m_distance) - (Distance1000 * 100 + Distance100 * 10); // s£(10mΜ)

			double tmp_location = Location + m_distDef; // ρΤΚuβ³πKp·ι
			Location1000 = tmp_location / 1000; // ρΤΚu(kmΜ)
			Location100 = (tmp_location / 100) - (Location1000 * 10); // ρΤΚu(100mΜ)
			Location10 = (tmp_location / 10) - (Location1000 * 100 + Location100 * 10); // ρΤΚu(10mΜ)
*/
			if(temp_distance >= 100 && Distance100 == 0){Distance100 = 10;}
			if(temp_distance >= 10 && Distance10 == 0){Distance10 = 10;}

			TimsSpeed100 = fabs(*TrainSpeed) / 100;
			TimsSpeed10 = (fabs(*TrainSpeed) / 10) - (TimsSpeed100 * 10);
			TimsSpeed1 = fabs(*TrainSpeed) - (TimsSpeed100 * 100 + TimsSpeed10 * 10);

			if(*TrainSpeed >= 1000 && TimsSpeed100 == 0){TimsSpeed100 = 10;}
			if(*TrainSpeed >= 100 && TimsSpeed10 == 0){TimsSpeed10 = 10;}
			if(TimsSpeed1 == 0){TimsSpeed1 = 10;}

			m_tmrTims = 1200;
		}

		// jbg\¦
		for(int i=0;i<10;i++) // σΤΜXVAjbgσΤπ10ρ[v
		{
			// TIMSp
			if(Current > 0 && UnitTims[i] != 1 && rand() % RANDOMIZE_UNITTIMS == 0){UnitTims[i] = 1;}
			else if(Current < 0 && UnitTims[i] != 2 && rand() % RANDOMIZE_UNITTIMS == 0){UnitTims[i] = 2;}
			else if(Current == 0 && UnitTims[i] != 0 && rand() % RANDOMIZE_UNITTIMS == 0){UnitTims[i] = 0;}

			// \¦p
			if(Current != 0 && UnitState[i] != 1 && rand() % RANDOMIZE_UNITLAMP == 0){UnitState[i] = 1;}
			else if(Current == 0 && UnitState[i] != 0 && rand() % RANDOMIZE_UNITLAMP == 0){UnitState[i] = 0;}
		}

		// isϋόξσ
		switch(Direction)
		{
		case 0: //ϋόπ0Ι΅½κ
			ArrowDirection = 0;
			break;
		case 1: //ϋόπ1Ι΅½κ
			switch(*Reverser)
			{
			case 1: //o[TͺOiΘηA1πΤ·
				ArrowDirection = 1;
				break;
			case -1: //o[TͺγήΘηA2πΤ·
				ArrowDirection = 2;
				break;
			case 0: //o[TͺΨΘηA0πΤ·
			default:
				ArrowDirection = 0;
				break;
			}
			break;
		case 2:
			switch(*Reverser)
			{
			case 1: //o[TͺOiΘηA2πΤ·
				ArrowDirection = 2;
				break;
			case -1: //o[TͺγήΘηA1πΤ·
				ArrowDirection = 1;
				break;
			case 0: //o[TͺΨΘηA0πΤ·
			default:
				ArrowDirection = 0;
				break;
			}
			break;
		}

		// vbVAbvCxg
		if(*TrainSpeed != 0) // wWvπO·ι
		{
			if((m_pushUpFlag == 2 && (m_pushUpBeacon == 1 || *TrainSpeed < 2.0f)) || (m_pushUpFlag == -1 && m_dist <= 0))//ΚίΙ£φΚίorβΤΙ¬x2LΘΊ
			{
				m_pushUpFlag = 0;

				// XebvXVΜρΎ―[v
				for( ;m_pushUpCount>0;m_pushUpCount--)
				{
					if(m_pushUpCount > 1)
					{
						for(int i=0;i<10;i++)
						{
							PushUp(i);
						}
					}
					else
					{
						m_tmrVisible = *Time;
						for(int i=0;i<10;i++)
						{
							m_update[i] = 1;

							// 3ρΪΜAwπΕVΙ·ιAΜwπΕVΙ·ιAρΤπXV·ι
							if(i == 3)
							{
								PushNext();
								PushTimeStation();
								PushTrainNumber();
								PushSESta();
							}
						}
					}
				}
				//20180824bθΗΑ
				//y[Wί­θ΅Θ’
				if(m_option > 0)
				{
					PushNext(); // wπΕVΙ·ι
					PushTimeStation(); //ΜwπΕVΙ·ι
					PushTrainNumber(); //ρΤπXV·ι
				}
			}
		}
		else if(m_pushUpFlag == 3 || m_pushUpBeacon == 2) // wWvΜΖ«
		{
			m_pushUpFlag = 0;
			PushNext(); // wπΕVΙ·ι
			PushTimeStation(); //ΜwπΕVΙ·ι
			PushTrainNumber(); //ρΤπXV·ι
			PushSESta();

			for(int i=0;i<10;i++)
			{
				PushUp(i);
			}
		}
		else if(m_pushUpFlag == -1) // N?Μϊ»
		{
			PushNext(); // wπΕVΙ·ι
			PushTimeStation(); //ΜwπΕVΙ·ι
			PushTrainNumber(); //ρΤπXV·ι
			PushSESta();
		}

		// XebvXVΜ
		for(int i=0;i<10;i++)
		{
			if(*Time >= m_tmrVisible + (i * (90 * (2 / 3))) && *Time <= m_tmrVisible + 90 * (i + 1) - (90 * (1 / 3)))
			{
				HiddenLine[i] = 1;

				if(m_update[i] == 1)
				{
					m_update[i] = 0;
					PushUp(i);
				}
			}
			else
			{
				HiddenLine[i] = 0;
			}
		}
	}

	// hAͺJ’½
	void DoorOpening(void)
	{
		m_door = 0; // hAσΤ
		m_tmrVisible = 0; // \¦ΜXVπ³ΉΘ’
	}

	// hAͺΒάΑ½
	void DoorClosing(void)
	{
		m_door = 1; // hAσΤ
	}

	// wΪί΅½
	//void Receive(int data) //20180824bθP
	void Receive(int data,int option) //20180824bθΗΑ
	{
		m_pushUpFlag = data >= 0 ? 1 : -1;
		m_pushUpBeacon = 0;
		m_pushUpCount = abs(data) > 100000 ? 0 : abs(data) / 10000 > 0 ? abs(data) / 10000 : 1;//100000ζθ½’ΖvbVAbv΅Θ’
		m_option = abs(option) > 0 ? 1 : 0; //20180824bθΗΑ

		m_dist = abs(data % 10000) - TIMS_OFFSET;
		m_blinking = false;

		m_pathStaDist = abs(data % 10000) + 5.0F;

		if(*TrainSpeed == 0) // wWvπO·ι
		{
			// m_pushUpFlag = abs(data) < 1000000 ? 3 : 0;
			m_pushUpFlag = abs(data) < 100000 ? 3 : 0;
			m_pushUpCount = 0;
			m_dist = 0;
			m_pathStaDist = 0;
		}
	}

	// \¦πXV·ι
	void UpdateView(void)
	{
		m_pushUpBeacon = *TrainSpeed != 0 ? 1 : 2; // \¦XVΜnγq
	}

	// ©wAwΜέθ
	void SetNext(int data)
	{
		m_thisName = data / 1000;
		m_nextName = data % 1000;
	}

	// ©wAwΜέθ
	void SetNextTime(int data)
	{
		m_nextTime[0] = data / 10000;
		m_nextTime[1] = ((data % 10000) - (data % 100)) / 100;
		m_nextTime[2] = (data % 100) / 5;	
	}

	// wΤόΜέθ
	void SetNextTrack(int data)
	{
		m_nextTrack = data;
	}

	// ρΤνΚΜέθ
	void SetKind(int data)
	{
		m_kind = data;
	}

	// ρΤΤΜέθ
	void SetNumber(int data, int chara)
	{
		m_charactor = chara;//νΚΝΊ2
		
		if(data >= 1000) //ρΤͺ1000ΘγΘη
		{
			//1000ΘγΕ1000Κͺ0Θη0π\¦
			m_number[0] = (data / 1000) % 10 == 0 ? 10 : (data / 1000) % 10; //ρΤηΚΝ1000Κ
		}
		else
		{
			m_number[0] = 0; //’Ν³\¦
		}

		if(data >= 100) //ρΤͺ100ΘγΘη
		{
			//100ΘγΕ100Κͺ0Θη0π\¦
			m_number[1] = (data / 100) % 10 == 0 ? 10 : (data / 100) % 10; //ρΤSΚΝ100Κ
		}
		else
		{
			m_number[1] = 0; //’Ν³\¦
		}

		if(data >= 10) //ρΤͺ10ΘγΘη
		{
			m_number[2] = (data / 10) % 10 == 0 ? 10 : (data / 10) % 10; //ρΤ\ΚΝ10Κ
		}
		else
		{
			m_number[2] = 0; //’Ν³\¦
		}

		m_number[3] = data % 10 == 0 ? 10 : data % 10; //γόlͺ0Θη10Ι·ιAΌΝ1Κ

	}

	// ^sζΤΜέθ
	void SetLeg(int data)
	{
		m_from = data / 1000;
		m_destination = data % 1000;
	}

	// sζΜέθ
	void SetFor(int data)
	{
		m_for = data;
	}

	// sζΤΜέθ
	void SetCrawl(int data)
	{
		if(data > 0)
		{
			Crawl = 1;
			CrawlLimit = data / 5;
		}
		else
		{
			Crawl = 0;
			CrawlLimit = 0;
		}
	}

	// ^pΜέθ
	void SetAfteruent(int type, int data, int chara)
	{
		if(type == 0) // ρΤΤ
		{
			/*
			AfterChara = data / 10000;
			AfterNumber[0] = ((data % 10000) - (data % 1000)) / 1000;
			AfterNumber[1] = ((data % 1000) - (data % 100)) / 100;
			AfterNumber[2] = ((data % 100) - (data % 10)) / 10;
			AfterNumber[3] = data % 10;
			*/
			m_afterChara = chara;
			
			if(data >= 1000) //ρΤͺ1000ΘγΘη
			{
				//1000ΘγΕ1000Κͺ0Θη0π\¦
				m_afterNumber[0] = (data / 1000) % 10 == 0 ? 10 : (data / 1000) % 10; //ρΤηΚΝ1000Κ
			}
			else
			{
				m_afterNumber[0] = 0; //’Ν³\¦
			}

			if(data >= 100) //ρΤͺ100ΘγΘη
			{
				//100ΘγΕ100Κͺ0Θη0π\¦
				m_afterNumber[1] = (data / 100) % 10 == 0 ? 10 : (data / 100) % 10; //ρΤSΚΝ100Κ
			}
			else
			{
				m_afterNumber[1] = 0; //’Ν³\¦
			}

			if(data >= 10) //ρΤͺ10ΘγΘη
			{
				m_afterNumber[2] = (data / 10) % 10 == 0 ? 10 : (data / 10) % 10; //ρΤ\ΚΝ10Κ
			}
			else
			{
				m_afterNumber[2] = 0; //’Ν³\¦
			}

			m_afterNumber[3] = data % 10 == 0 ? 10 : data % 10; //γόlͺ0Θη10Ι·ιAΌΝ1Κ
		}
		else if(type == 1) // 
		{
			m_afterTime[0][0] = data / 10000;
			m_afterTime[0][1] = ((data % 10000) - (data % 100)) / 100;
			m_afterTime[0][2] = (data % 100) / 5;
		}
		else if(type == 2) // ­Τ
		{
			m_afterTime[1][0] = data / 10000;
			m_afterTime[1][1] = ((data % 10000) - (data % 100)) / 100;
			m_afterTime[1][2] = (data % 100) / 5;
		}
		else if(type == 3) // νΚ
		{
			m_afterKind = data;
		}
		
			
	}

	// isϋόέθ
	void SetDirection(int direction)
	{
		switch(direction)
		{
		case 1: // Ά
			Direction = 1;
			break;
		case 2: // E
			Direction = 2;
			break;
		case 0:
		default: // αO
			Direction = 0;
			break;
		}
	}

	// sHI_wΜέθ
	void SetLastStop(int type, int data)
	{
		if(type == 0) // 
		{
			m_lastStopTime[0] = data / 10000;
			m_lastStopTime[1] = ((data % 10000) - (data % 100)) / 100;
			m_lastStopTime[2] = (data % 100) / 5;
		}
		else if(type == 1) // o­
		{
			m_lastStopTimeL[0] = data / 10000;
			m_lastStopTimeL[1] = ((data % 10000) - (data % 100)) / 100;
			m_lastStopTimeL[2] = (data % 100) / 5;
		}
		else if(type == 2) // Τό
		{
			m_lastStopTrack = data;
		}
	}

	// sHI_wΌέθ
	void SetRelayStation(int data)
	{
		m_relayName = data;
	}

	// ΜwΤόέθ
	void SetTimeStationTime(int type, int data)
	{
		if(type == 0) // ΌOΜw
		{
			m_beforeTime[0] = data / 10000;
			m_beforeTime[1] = ((data % 10000) - (data % 100)) / 100;
			m_beforeTime[2] = (data % 100) / 5;
		}
		else if(type == 1) // Μw
		{
			m_afterTimeA[0] = data / 10000;
			m_afterTimeA[1] = ((data % 10000) - (data % 100)) / 100;
			m_afterTimeA[2] = (data % 100) / 5;
		}
		else if(type == 2) // Μw­
		{
			m_afterTimeL[0] = data / 10000;
			m_afterTimeL[1] = ((data % 10000) - (data % 100)) / 100;
			m_afterTimeL[2] = (data % 100) / 5;
		}
		else if(type == 3) // ΌOΜwΤό
		{
			m_beforeTrack = data;
		}
		else if(type == 4) // ΜwΤό
		{
			m_afterTrack = data;
		}
	}

	//ΜwwΌΜέθ
	void SetTimeStationName(int type, int data)
	{
		if(type == 0) // ΌOΜwέθ
		{
			m_beforeName = data;
		}
		else if(type == 1) // Μwέθ
		{
			m_afterName = data;
		}
	}

	//ΠόpwΌΜέθ
	void SetSESta(int sta)
	{
		m_seSta = sta; //wΌf[^πόκι
	}

	//ΠόpwΌέ
	void SetSEStaExtra(int data)
	{
		SESta[0] = data;
	}

	//Πόp^]ϋό
	void SetSEDirection(int data, int area)
	{
		SEDirection = data == 0 ? -1 : 1; //γθdΤΕΝΈZ
		if (area >= 51)
			SEArea = 1;//Ίθ½όEγθVhs«
		if (area >= 31)
			SEArea = 2;//Ίθ]mό
		else
			SEArea = 0;//Ίθ¬c΄όEγθηγcό
	}

	// sH\ξσΜέθ
	void SetArrowState(int data)
	{
		TrainArrow = data;
	}

	// s£Μέθ
	void SetDistance(float distance, int data)
	{
		StartingPoint = distance; // £vZΜN_

		if(data >= 100000) // £ΈZ·ι©Η€©
		{
			m_direction = -1;
		}
		else 
		{
			m_direction = 1;
		}

		m_distance = data % 100000; // s£
	}

	// ρΤΚuβ³Μέθ
	void SetPositionDef(int data)
	{
		m_distDef = data; // ρΤΚuΜβ³
	}

	// X^te[uΜ«έ
	void InputLine(int colum, int line, int data)
	{
		switch(colum) // ρΜUθͺ―
		{
		case 0:
			Span[line][0] = data / 100;
			Span[line][1] = (data % 100) / 5;
			break;
		case 1:
			Station[line] = data;
			break;
		case 2:
			Arrive[line][0] = data / 10000;
			Arrive[line][1] = ((data % 10000) - (data % 100)) / 100;
			Arrive[line][2] = (data % 100) / 5;
			break;
		case 3:
			Leave[line][0] = data / 10000;
			Leave[line][1] = ((data % 10000) - (data % 100)) / 100;
			Leave[line][2] = (data % 100) / 5;
			break;
		case 4:
			Track[line] = data;
			break;
		case 5:
			Limit[line] = data / 5;
			break;
		case 6:
			Limit2[line] = data / 5;
			break;
		}
	}

	// JΚξρΜβ~Β»­ξρπXV·ι
	void CheckPath(int signal, float dist=0, int section=0)
	{
		if((signal == 0 || signal == 9 || signal == 10) && dist > 0)
		{
			m_pathSecDist[section] = dist; // JΚξρΜΒ»­ξρ
			m_passSecLine[section] = 0; // JΚξρΜΒ»­ζΨθό
		}
		else
		{
			m_pathSecDist[section] = 0;
			m_passSecLine[section] = dist;
		}
	}

	// ρνu[LΙπΉπΔΆ·ι
	void PlaySoundAirHigh(int state, int newState)
	{
		if(state == EmergencyNotch && newState < EmergencyNotch && BcPressure > 340)
		{
			m_airHigh = ATS_SOUND_PLAY;
			m_tmrBcPressCut = *Time + ini_cutPressTime; // u[LΈ³Μ^C}[
		}
	}

	// ρνu[LϊπΔΆ·ι
	void PlaySoundEmgAnnounce(int state, int newState)
	{
		if(state != EmergencyNotch && newState == EmergencyNotch && *TrainSpeed > 5.0F) //ρνu[Lϊ¬x
		{
			m_emgAnnounce = ATS_SOUND_PLAY;
		}
	}

	// ρN?f¬νΉπZbg·ι
	void SetLbInit(int pos, int enable)
	{
		if(pos == 0 && enable == 1)
		{
			event_lbInit = 1;
		}
	}

	// u[LΈ³Ή(ρν)πΔΆ·ι
	void PlaySoundAirApplyEmg(int state, int newState)
	{
		if(state != EmergencyNotch && newState == EmergencyNotch && BcPressure < 150.0f)
		{
			m_airApplyEmg = ATS_SOUND_PLAY;
		}
	}

	// πΌΨΦπs€
	void SetACDC(int state)
	{
		step_ACDC = state;
		tmr_ACDC = *Time;
	}

	// πΌΨΦΜ¨mηΉ
	void AlartACDC(int state)
	{
		alert_ACDC = state;
	}

	// _V[hπΟX·ι
	void RandomizeSeed(void)
	{
		srand(*Time);
	}

private: //[Ζ΅Δg€ΰΜ
	int m_door; // hAσΤ
	float m_dist; // β~\θ_£
	bool m_blinking; // w_Ε©Η€©

	int m_pushUpFlag; // \¦XVΜtO
	int m_pushUpBeacon; // \¦XVΜnγq
	int m_pushUpCount; // \¦XVΜJθΤ΅
	int m_tmrVisible; // j^ΜXebvXV
	int m_update[7]; // XebvXVΜσΤ
	int m_thisName; // ©wΌ
	int m_nextName; // wΌ
	int m_nextTime[3]; // w
	int m_nextTrack; // wΤό

	//ΜwpΗΑ
	int m_beforeName; // OΜwΌ
	int m_afterName; // ΜwΌ
	int m_beforeTime[3]; //OΜw
	int m_afterTimeA[3]; //Μw
	int m_afterTimeL[3]; //Μw­
	int m_beforeTrack; // OΜwΤό
	int m_afterTrack; // ΜwΤό
	int m_lastStopTime[3]; // I_( - ͺ - b)
	int m_lastStopTimeL[3]; // I_o­( - ͺ - b)
	int m_lastStopTrack; // I_Τό
	int m_relayName; // sHI_wΌ

	//20181014bθΗΑ
	int m_from; //^sp^[­w
	int m_destination; //^sp^[w
	int	m_for; //ρΤsζ

	//20180824bθΗΑ
	int m_option; //wΖΜwΜέXV·ι

	//20181014bθΗΑ
	int m_kind; // ρΤνΚ(Κίέθάή)
	int m_number[4]; // ρΤΤ(1000 - 100 - 10 - 1)
	int m_charactor; // ρΤΤ(L)
	int m_afterNumber[4]; // ^pρΤΤ(1000 - 100 - 10 - 1)
	int m_afterChara; // ^pL
	int m_afterTime[2][3]; // ^p­
	int m_afterKind; //^pνΚ

	float m_pathStaDist; // JΚξρΜwΚuξρ
	float m_pathSecDist[10]; // JΚξρΜΒ»­ξρ
	float m_passSecLine[10]; // JΚξρΜΒ»­ζΨθό

	double m_distance; // s£
	int m_direction; // £ΈZ·ι©Η€©
	double m_distDef; // ρΤΚuΜβ³

	int m_tmrUpdate; // ¬xvΜXV^C}[
	int m_tmrTims; // Ej^[ΜXV^C}[
	int m_tmrBcPressCut; // u[LΈ³Μ^C}[

	int m_relayD; // sm[
	int m_lbInit; // ρN?f¬νΉ
	int m_airHigh; // ρνu[LΙπΉ
	int m_airApply; // u[LΈ³Ή
	float m_bcPrsDelta; // u[LV_³Ν[kPa]
	int m_emgAnnounce; // ρνu[Lϊ
	int m_airApplyEmg; // u[LΈ³Ή(ρν)
	int m_updateInfo; // ^sξρXV
	int m_deltaUpdate; // Oρ^sξρXV

	//Πόp
	int m_seSta;

	// X^te[uΜvbVAbv
	void PushUp(int line)
	{
		if(line == 9) //10sΪΜΘOZbg
		{
			Station[line] = 0;
			Track[line] = 0;
			Limit[line] = 0;
			Limit2[line] = 0;
			Span[line][0] = 0;
			Span[line][1] = 0;
		}
		else //1©η9sΪΜJθγ°
		{
			Station[line] = Station[line + 1];
			Track[line] = Track[line + 1];
			Limit[line] = Limit[line + 1];
			Limit2[line] = Limit2[line + 1];
			Span[line][0] = Span[line + 1][0];
			Span[line][1] = Span[line + 1][1];
		}

		for(int j=0;j<3;j++) //­ΜZbg
		{
			if(line == 9) //10sΪπσΙ·ι
			{
				switch(j)
				{
				case 0:
					Arrive[line][j] = 0;
					Leave[line][j] = 0;
					break;
				case 1:
					Arrive[line][j] = 0;
					Leave[line][j] = 0;
					break;
				case 2:
					Arrive[line][j] = 0;
					Leave[line][j] = 0;
					break;
				}
				
			}
			else //1©η9sΪΝJθγ°
			{
				Arrive[line][j] = Arrive[line + 1][j];
				Leave[line][j] = Leave[line + 1][j];
			}
		}
	}

	//ΠόpwΌπXV
	void PushSESta(void)
	{
		SESta[0] = m_seSta;
	}



	// όΝ³κΔ’ιwπζΚΙ½f
	void PushNext(void)
	{
		This = m_thisName;
		Next = m_nextName;
		NextTime[0] = m_nextTime[0];
		NextTime[1] = m_nextTime[1];
		NextTime[2] = m_nextTime[2];
		NextTrack = m_nextTrack;
	}

	// όΝ³κΔ’ιΜwπζΚΙ½f
	void PushTimeStation(void)
	{
		Before = m_beforeName; //ΌOΜw
		After = m_afterName; //Μw
		RelayName = m_relayName; //~Τw

		BeforeStationTime[0] = m_beforeTime[0];
		BeforeStationTime[1] = m_beforeTime[1];
		BeforeStationTime[2] = m_beforeTime[2];

		AfterStationTimeA[0] = m_afterTimeA[0];
		AfterStationTimeA[1] = m_afterTimeA[1];
		AfterStationTimeA[2] = m_afterTimeA[2];

		AfterStationTimeL[0] = m_afterTimeL[0];
		AfterStationTimeL[1] = m_afterTimeL[1];
		AfterStationTimeL[2] = m_afterTimeL[2];

		LastStopTime[0] = m_lastStopTime[0];
		LastStopTime[1] = m_lastStopTime[1];
		LastStopTime[2] = m_lastStopTime[2];

		LastStopTimeL[0] =  m_lastStopTimeL[0];
		LastStopTimeL[1] =  m_lastStopTimeL[1];
		LastStopTimeL[2] =  m_lastStopTimeL[2];

		BeforeTrack = m_beforeTrack;
		AfterTrack = m_afterTrack;
		LastStopTrack = m_lastStopTrack;

		//20181018bθΗΑ
		From = m_from; //^sp^[­w
		Destination = m_destination; //^sp^[w
		For = m_for; //ρΤsζ

	}

	//20181018bθΗΑ
	//όΝ³κΔ’ιρΤΤΖνΚπζΚΙ½f
	void PushTrainNumber(void)
	{
		//»ένΚρΤ
		Kind = m_kind % 100;
		PassMode = (m_kind >= 100) ? (m_kind / 100) : 0; // Κίέθ

		Number[0] = m_number[0];
		Number[1] = m_number[1];
		Number[2] = m_number[2];
		Number[3] = m_number[3];
		Charactor = m_charactor;
	
		//sHρΤ
		AfterKind = m_afterKind;
		AfterNumber[0] = m_afterNumber[0];
		AfterNumber[1] = m_afterNumber[1];
		AfterNumber[2] = m_afterNumber[2];
		AfterNumber[3] = m_afterNumber[3];
		AfterChara = m_afterChara;

		//sH­
		AfterTime[0][0] = m_afterTime[0][0];
		AfterTime[0][1] = m_afterTime[0][1];
		AfterTime[0][2] = m_afterTime[0][2];

		AfterTime[1][0] = m_afterTime[1][0];
		AfterTime[1][1] = m_afterTime[1][1];
		AfterTime[1][2] = m_afterTime[1][2];
	}

	// zρΜϊ»
	void ResetArray(void)
	{
		for(int c3=0;c3<3;c3++) // 3ρ[vAζ±IΉwΜZbg
		{
			LastStopTime[c3] = 0;
			LastStopTimeL[c3] = 0;
			m_nextTime[c3] = 0;

			for(int c3_2=0;c3_2<2;c3_2++) // 2ρ[vAsHΜZbg
			{
				AfterTime[c3_2][c3] = 0;
			}
		}

		for(int st3=0;st3<3;st3++) // 3ρ[vAΜwΜZbg
		{
			BeforeStationTime[st3] = 0;
			AfterStationTimeA[st3] = 0;
			AfterStationTimeL[st3] = 0;
			m_beforeTime[st3] = 0;
			m_afterTimeA[st3] = 0;
			m_afterTimeL[st3] = 0;
		}

		for(int c4=0;c4<4;c4++) // 4ρ[vAρΤΜZbg
		{
			Number[c4] = 10;
			AfterNumber[c4] = 10;
		}

		for(int c10=0;c10<10;c10++) // 10ρ[vAΘOΜX^te[uΜZbg
		{
			Station[c10] = 0;
			PassSta[c10] = 0;
			Track[c10] = 0;
			Limit[c10] = 0;
			Limit2[c10] = 0;

			HiddenLine[c10] = 0;
			m_update[c10] = 0;

			TrackPath[c10] = 0;
			UnitTims[c10] = 0;
			UnitState[c10] = 0;
			m_pathSecDist[c10] = 0;
			m_passSecLine[10] = 0;

			// e[uΙΝ 00:00:00 (0, 0, 0) πoΝ
			for(int c10_3=0;c10_3<3;c10_3++) // 10ρ»κ»κΙ3ρΈΒ[v
			{
				switch(c10_3)
				{
				case 0:
					Arrive[c10][c10_3] = 0;
					Leave[c10][c10_3] = 0;
					Span[c10][c10_3] = 0;
					break;
				case 1:
					Arrive[c10][c10_3] = 0;
					Leave[c10][c10_3] = 0;
					Span[c10][c10_3] = 0;
					break;
				case 2:
					Arrive[c10][c10_3] = 0;
					Leave[c10][c10_3] = 0;
					break;
				}
			}
		}

		for(int c120=0;c120<120;c120++) // 120ρ[vAJΚξρΜZbg
		{
			TrackPath2[c120] = 0;
		}
	}
};	// CTims

class CSpp
{
private:
	float m_dist; // β~\θ_£
	bool m_played;
	bool m_halt;
	int m_haltChime;
	int m_haltChime2;
	int m_haltChime3;
	int m_passAlarm;

public:
	float *TrainSpeed; // ρΤ¬x[km/h]
	int *DeltaT; // t[Τ
	int *BrakeNotch; // »έΜu[Lmb`

	int HaltChime; // βΤ`C
	int HaltChime2; // βΤ`C[v
	int HaltChime3; // βΤ`C[v(Έ­΅Θ’)
	int PassAlarm; // ΚίΔΰΉΊ
	int ServiceNotch; // ATSmFmb`

	void RunSpp(void)
	{
		float speed = fabsf(*TrainSpeed); // ¬xΜβΞl[km/h]
		float def = speed / 3600 * *DeltaT; // 1t[Ε?’½£(βΞl)[m]
		m_dist -= def; // cθ£πΈZ·ι

		// xρπΒη·
		if(speed * speed / SPP_DECELERATION >= m_dist - 50 && m_dist > 0 && !m_played) // ¬xΖΈ (p^[)
		{
			m_played = true;
			if(m_halt) // βΤΜκ
			{
// #if(SPP_ALARMTYPE) // 1ρ­Ή^
			m_haltChime = ATS_SOUND_PLAY;
// #else              // JθΤ΅­Ή^
			m_haltChime3 = ATS_SOUND_PLAYLOOPING;
			if(*BrakeNotch >= ServiceNotch)
			{
				m_haltChime2 = -1200; // u[Lπί½κΝΉΚπ¬³­·ι (-12dB)
			}
			else
			{
				m_haltChime2 = 0;
			}
// #endif
			}
			else // ΚίΜκ
			{
				m_passAlarm = ATS_SOUND_PLAY;
			}
		}

		// TEhπXV
		HaltChime = m_haltChime;
		HaltChime2 = m_haltChime2;
		HaltChime3 = m_haltChime3;
		PassAlarm = m_passAlarm;

		// CONTINUEΙ΅Δ¨­
		if(m_haltChime == ATS_SOUND_PLAY){m_haltChime = ATS_SOUND_CONTINUE;}
		if(m_haltChime2 == ATS_SOUND_PLAY){m_haltChime2 = ATS_SOUND_CONTINUE;}
		if(m_haltChime3 == ATS_SOUND_PLAYLOOPING){m_haltChime3 = ATS_SOUND_CONTINUE;}
		m_passAlarm = ATS_SOUND_CONTINUE;
	}

	void InitSpp(void)
	{
		m_dist = 0;
		m_haltChime = ATS_SOUND_STOP;
		m_haltChime2 = ATS_SOUND_STOP;
		m_haltChime3 = ATS_SOUND_STOP;
	}

	void Receive(int data)
	{
		m_halt = data >= 0;
		m_dist = abs(data) - SPP_OFFSET;
		m_played = false;
		m_haltChime = ATS_SOUND_STOP;
		m_haltChime2 = ATS_SOUND_STOP;
		m_haltChime3 = ATS_SOUND_STOP;
	}

	void NotchChanged(void)
	{
		// u[Lπί½κΝΉΚπ¬³­·ι (-12dB)
		if(m_haltChime2 == 0 && *BrakeNotch >= ServiceNotch){m_haltChime2 = -1200;}
	}

	void StopChime(void)
	{
		m_haltChime = ATS_SOUND_STOP;
		m_haltChime2 = ATS_SOUND_STOP;
		m_haltChime3 = ATS_SOUND_STOP;
	}
};	// CSpp

class CDate
{
public:
	// ΤΟE\’Μ
	time_t t;
	struct tm *status;

	// oΝ
	int Cooler; // β[
	int CoolerSound; // β[Ή

	// ϊ»·ι
	void initialize(void)
	{
		m_month = 0; // 

		Cooler = 0; // β[
		CoolerSound = ATS_SOUND_STOP; // β[Ή

		update();
	}

	// ϊtπXV·ι
	void update(void)
	{
		time(&t);
		status = localtime(&t);
		m_month = status->tm_mon + 1;

		// β[Μ§δ
		if(Cooler == 0)
		{
			Cooler = (m_month >= 6 && m_month <= 9);
		}
	}

private:
	int m_month; // (1`12)
};	// CDate
