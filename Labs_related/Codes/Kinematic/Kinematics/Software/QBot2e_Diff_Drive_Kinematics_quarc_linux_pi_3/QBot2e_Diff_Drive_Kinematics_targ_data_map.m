  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 7;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (QBot2e_Diff_Drive_Kinematics_P)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_end_time
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_input
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_inp_b
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_inp_c
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.SecondOrderLowPassFilter2_inp_e
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_start_time
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.BiasRemoval_switch_id
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILRead1_analog_channels
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILRead1_digital_channels
	  section.data(2).logicalSrcIdx = 8;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILRead1_encoder_channels
	  section.data(3).logicalSrcIdx = 9;
	  section.data(3).dtTransOffset = 4;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILRead1_other_channels
	  section.data(4).logicalSrcIdx = 10;
	  section.data(4).dtTransOffset = 6;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILWrite_other_channels
	  section.data(5).logicalSrcIdx = 11;
	  section.data(5).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 40;
      section.data(40)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_P.Disable_Value
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Enable_Value
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.unity_Value
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.UnitDelay_InitialCondition
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Sumk1n1xk_InitialCondition
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.zero_Y0
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Constant_Value
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Vbiased_Y0
	  section.data(8).logicalSrcIdx = 19;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Vunbiased_Y0
	  section.data(9).logicalSrcIdx = 20;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Stepstart_time_Y0
	  section.data(10).logicalSrcIdx = 21;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Stepstart_time_YFinal
	  section.data(11).logicalSrcIdx = 22;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Stepend_time_Y0
	  section.data(12).logicalSrcIdx = 23;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Stepend_time_YFinal
	  section.data(13).logicalSrcIdx = 24;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOTerminate
	  section.data(14).logicalSrcIdx = 25;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOExit
	  section.data(15).logicalSrcIdx = 26;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOStart
	  section.data(16).logicalSrcIdx = 27;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOEnter
	  section.data(17).logicalSrcIdx = 28;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POFinal
	  section.data(18).logicalSrcIdx = 29;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOFinal
	  section.data(19).logicalSrcIdx = 30;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIHigh
	  section.data(20).logicalSrcIdx = 31;
	  section.data(20).dtTransOffset = 22;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AILow
	  section.data(21).logicalSrcIdx = 32;
	  section.data(21).dtTransOffset = 28;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POFrequency
	  section.data(22).logicalSrcIdx = 33;
	  section.data(22).dtTransOffset = 34;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POInitial
	  section.data(23).logicalSrcIdx = 34;
	  section.data(23).dtTransOffset = 35;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOInitial
	  section.data(24).logicalSrcIdx = 35;
	  section.data(24).dtTransOffset = 36;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Integrator2_IC
	  section.data(25).logicalSrcIdx = 36;
	  section.data(25).dtTransOffset = 40;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Integrator2_IC_f
	  section.data(26).logicalSrcIdx = 37;
	  section.data(26).dtTransOffset = 41;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Constant2_Value
	  section.data(27).logicalSrcIdx = 38;
	  section.data(27).dtTransOffset = 42;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Constant_Value_l
	  section.data(28).logicalSrcIdx = 39;
	  section.data(28).dtTransOffset = 43;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.tickstoencoderrotation_Gain
	  section.data(29).logicalSrcIdx = 40;
	  section.data(29).dtTransOffset = 44;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.encoderrotationtowheelrotationg
	  section.data(30).logicalSrcIdx = 41;
	  section.data(30).dtTransOffset = 45;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.wheelradiousmm_Gain
	  section.data(31).logicalSrcIdx = 42;
	  section.data(31).dtTransOffset = 46;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.mmtom_Gain
	  section.data(32).logicalSrcIdx = 43;
	  section.data(32).dtTransOffset = 47;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Constant_Value_f
	  section.data(33).logicalSrcIdx = 44;
	  section.data(33).dtTransOffset = 48;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.x0_Value
	  section.data(34).logicalSrcIdx = 45;
	  section.data(34).dtTransOffset = 49;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.tickstoencoderrotation_Gain_a
	  section.data(35).logicalSrcIdx = 46;
	  section.data(35).dtTransOffset = 50;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.encoderrotationtowheelrotatio_m
	  section.data(36).logicalSrcIdx = 47;
	  section.data(36).dtTransOffset = 51;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.wheelradiousmm_Gain_b
	  section.data(37).logicalSrcIdx = 48;
	  section.data(37).dtTransOffset = 52;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.mmtom_Gain_n
	  section.data(38).logicalSrcIdx = 49;
	  section.data(38).dtTransOffset = 53;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.Constant_Value_o
	  section.data(39).logicalSrcIdx = 50;
	  section.data(39).dtTransOffset = 54;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.x0_Value_b
	  section.data(40).logicalSrcIdx = 51;
	  section.data(40).dtTransOffset = 55;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIInitial
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POModes
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POConfiguration
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POAlignment
	  section.data(4).logicalSrcIdx = 55;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POPolarity
	  section.data(5).logicalSrcIdx = 56;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 57;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DIChannels
	  section.data(2).logicalSrcIdx = 58;
	  section.data(2).dtTransOffset = 6;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 59;
	  section.data(3).dtTransOffset = 37;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 60;
	  section.data(4).dtTransOffset = 41;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 61;
	  section.data(5).dtTransOffset = 43;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 62;
	  section.data(6).dtTransOffset = 44;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOChannels
	  section.data(7).logicalSrcIdx = 63;
	  section.data(7).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 65;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 66;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 67;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 68;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 69;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 70;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 71;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 72;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 73;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 74;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 75;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 76;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 77;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 78;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 79;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 80;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 81;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 82;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 83;
	  section.data(20).dtTransOffset = 19;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 84;
	  section.data(21).dtTransOffset = 20;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 85;
	  section.data(22).dtTransOffset = 21;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 86;
	  section.data(23).dtTransOffset = 22;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 87;
	  section.data(24).dtTransOffset = 23;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 88;
	  section.data(25).dtTransOffset = 24;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 89;
	  section.data(26).dtTransOffset = 25;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 90;
	  section.data(27).dtTransOffset = 26;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 91;
	  section.data(28).dtTransOffset = 27;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 92;
	  section.data(29).dtTransOffset = 28;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 93;
	  section.data(30).dtTransOffset = 29;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 94;
	  section.data(31).dtTransOffset = 30;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 95;
	  section.data(32).dtTransOffset = 31;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 96;
	  section.data(33).dtTransOffset = 32;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 97;
	  section.data(34).dtTransOffset = 33;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 98;
	  section.data(35).dtTransOffset = 34;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILRead1_Active
	  section.data(36).logicalSrcIdx = 99;
	  section.data(36).dtTransOffset = 35;
	
	  ;% QBot2e_Diff_Drive_Kinematics_P.HILWrite_Active
	  section.data(37).logicalSrcIdx = 100;
	  section.data(37).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_P.EnableSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 101;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 3;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (QBot2e_Diff_Drive_Kinematics_B)
    ;%
      section.nData     = 16;
      section.data(16)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_B.HILRead1_o4
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Product
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Product1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Product1_k
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.mmtom
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.x0
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Product_a
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.mmtom_e
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.x0_n
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Product_i
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.VVavg
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Vin
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Constant
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Count
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.Sum
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.div
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinemati_i.vC
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinemati_i.Omega
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinematics.vC
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_B.sf_Qbot2e_Diff_Drive_Kinematics.Omega
	  section.data(2).logicalSrcIdx = 20;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 8;
    sectIdxOffset = 3;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (QBot2e_Diff_Drive_Kinematics_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.Sumk1n1xk_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILWrite_OtherBuffer
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILRead1_PWORK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.Omega_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.Omega_0_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.vC_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.vC_0_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILWrite_PWORK
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 4;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 6;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 8;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 10;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 12;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILRead1_EncoderBuffer
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.Integrator1_IWORK_k
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_DW.SwitchCase_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_SubsysRanB
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Diff_Drive_Kinematics_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Diff_Drive_Kinematics_DW.EnabledMovingAverage_MODE
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 1805651504;
  targMap.checksum1 = 2439541167;
  targMap.checksum2 = 3586757282;
  targMap.checksum3 = 334487058;

