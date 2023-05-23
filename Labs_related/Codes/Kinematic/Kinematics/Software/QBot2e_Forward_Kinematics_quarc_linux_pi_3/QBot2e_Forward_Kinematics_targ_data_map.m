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
    ;% Auto data (QBot2e_Forward_Kinematics_P)
    ;%
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_P.BiasRemoval_end_time
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_P.SecondOrderLowPassFilter2_input
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_P.SecondOrderLowPassFilter2_inp_b
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Forward_Kinematics_P.SecondOrderLowPassFilter1_input
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Forward_Kinematics_P.SecondOrderLowPassFilter2_inp_p
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Forward_Kinematics_P.SecondOrderLowPassFilter2_inp_c
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Forward_Kinematics_P.SecondOrderLowPassFilter1_inp_p
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_P.BiasRemoval_start_time
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Forward_Kinematics_P.BiasRemoval_switch_id
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_P.HILRead1_analog_channels
	  section.data(1).logicalSrcIdx = 9;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_P.HILRead1_digital_channels
	  section.data(2).logicalSrcIdx = 10;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_P.HILRead1_encoder_channels
	  section.data(3).logicalSrcIdx = 11;
	  section.data(3).dtTransOffset = 4;
	
	  ;% QBot2e_Forward_Kinematics_P.HILRead1_other_channels
	  section.data(4).logicalSrcIdx = 12;
	  section.data(4).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_P.HILWrite_other_channels
	  section.data(5).logicalSrcIdx = 13;
	  section.data(5).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 45;
      section.data(45)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_P.Disable_Value
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_P.Enable_Value
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_P.unity_Value
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Forward_Kinematics_P.UnitDelay_InitialCondition
	  section.data(4).logicalSrcIdx = 17;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Forward_Kinematics_P.Sumk1n1xk_InitialCondition
	  section.data(5).logicalSrcIdx = 18;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Forward_Kinematics_P.zero_Y0
	  section.data(6).logicalSrcIdx = 19;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Forward_Kinematics_P.Constant_Value
	  section.data(7).logicalSrcIdx = 20;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_P.Vbiased_Y0
	  section.data(8).logicalSrcIdx = 21;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Forward_Kinematics_P.Vunbiased_Y0
	  section.data(9).logicalSrcIdx = 22;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Forward_Kinematics_P.Stepstart_time_Y0
	  section.data(10).logicalSrcIdx = 23;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Forward_Kinematics_P.Stepstart_time_YFinal
	  section.data(11).logicalSrcIdx = 24;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Forward_Kinematics_P.Stepend_time_Y0
	  section.data(12).logicalSrcIdx = 25;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Forward_Kinematics_P.Stepend_time_YFinal
	  section.data(13).logicalSrcIdx = 26;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_OOTerminate
	  section.data(14).logicalSrcIdx = 27;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_OOExit
	  section.data(15).logicalSrcIdx = 28;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_OOStart
	  section.data(16).logicalSrcIdx = 29;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_OOEnter
	  section.data(17).logicalSrcIdx = 30;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POFinal
	  section.data(18).logicalSrcIdx = 31;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_OOFinal
	  section.data(19).logicalSrcIdx = 32;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AIHigh
	  section.data(20).logicalSrcIdx = 33;
	  section.data(20).dtTransOffset = 22;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AILow
	  section.data(21).logicalSrcIdx = 34;
	  section.data(21).dtTransOffset = 28;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POFrequency
	  section.data(22).logicalSrcIdx = 35;
	  section.data(22).dtTransOffset = 34;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POInitial
	  section.data(23).logicalSrcIdx = 36;
	  section.data(23).dtTransOffset = 35;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_OOInitial
	  section.data(24).logicalSrcIdx = 37;
	  section.data(24).dtTransOffset = 36;
	
	  ;% QBot2e_Forward_Kinematics_P.Constant2_Value
	  section.data(25).logicalSrcIdx = 38;
	  section.data(25).dtTransOffset = 40;
	
	  ;% QBot2e_Forward_Kinematics_P.Constant_Value_h
	  section.data(26).logicalSrcIdx = 39;
	  section.data(26).dtTransOffset = 41;
	
	  ;% QBot2e_Forward_Kinematics_P.Integrator2_IC
	  section.data(27).logicalSrcIdx = 40;
	  section.data(27).dtTransOffset = 42;
	
	  ;% QBot2e_Forward_Kinematics_P.Integrator2_IC_l
	  section.data(28).logicalSrcIdx = 41;
	  section.data(28).dtTransOffset = 43;
	
	  ;% QBot2e_Forward_Kinematics_P.Integrator_IC
	  section.data(29).logicalSrcIdx = 42;
	  section.data(29).dtTransOffset = 44;
	
	  ;% QBot2e_Forward_Kinematics_P.Integrator2_IC_g
	  section.data(30).logicalSrcIdx = 43;
	  section.data(30).dtTransOffset = 45;
	
	  ;% QBot2e_Forward_Kinematics_P.Integrator_IC_l
	  section.data(31).logicalSrcIdx = 44;
	  section.data(31).dtTransOffset = 46;
	
	  ;% QBot2e_Forward_Kinematics_P.tickstoencoderrotation_Gain
	  section.data(32).logicalSrcIdx = 45;
	  section.data(32).dtTransOffset = 47;
	
	  ;% QBot2e_Forward_Kinematics_P.encoderrotationtowheelrotationg
	  section.data(33).logicalSrcIdx = 46;
	  section.data(33).dtTransOffset = 48;
	
	  ;% QBot2e_Forward_Kinematics_P.wheelradiousmm_Gain
	  section.data(34).logicalSrcIdx = 47;
	  section.data(34).dtTransOffset = 49;
	
	  ;% QBot2e_Forward_Kinematics_P.mmtom_Gain
	  section.data(35).logicalSrcIdx = 48;
	  section.data(35).dtTransOffset = 50;
	
	  ;% QBot2e_Forward_Kinematics_P.Constant_Value_n
	  section.data(36).logicalSrcIdx = 49;
	  section.data(36).dtTransOffset = 51;
	
	  ;% QBot2e_Forward_Kinematics_P.x0_Value
	  section.data(37).logicalSrcIdx = 50;
	  section.data(37).dtTransOffset = 52;
	
	  ;% QBot2e_Forward_Kinematics_P.tickstoencoderrotation_Gain_p
	  section.data(38).logicalSrcIdx = 51;
	  section.data(38).dtTransOffset = 53;
	
	  ;% QBot2e_Forward_Kinematics_P.encoderrotationtowheelrotatio_p
	  section.data(39).logicalSrcIdx = 52;
	  section.data(39).dtTransOffset = 54;
	
	  ;% QBot2e_Forward_Kinematics_P.wheelradiousmm_Gain_i
	  section.data(40).logicalSrcIdx = 53;
	  section.data(40).dtTransOffset = 55;
	
	  ;% QBot2e_Forward_Kinematics_P.mmtom_Gain_b
	  section.data(41).logicalSrcIdx = 54;
	  section.data(41).dtTransOffset = 56;
	
	  ;% QBot2e_Forward_Kinematics_P.Constant_Value_i
	  section.data(42).logicalSrcIdx = 55;
	  section.data(42).dtTransOffset = 57;
	
	  ;% QBot2e_Forward_Kinematics_P.x0_Value_i
	  section.data(43).logicalSrcIdx = 56;
	  section.data(43).dtTransOffset = 58;
	
	  ;% QBot2e_Forward_Kinematics_P.Constant_Value_d
	  section.data(44).logicalSrcIdx = 57;
	  section.data(44).dtTransOffset = 59;
	
	  ;% QBot2e_Forward_Kinematics_P.x0_Value_ie
	  section.data(45).logicalSrcIdx = 58;
	  section.data(45).dtTransOffset = 60;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_EIInitial
	  section.data(1).logicalSrcIdx = 59;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POModes
	  section.data(2).logicalSrcIdx = 60;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POConfiguration
	  section.data(3).logicalSrcIdx = 61;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POAlignment
	  section.data(4).logicalSrcIdx = 62;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POPolarity
	  section.data(5).logicalSrcIdx = 63;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 64;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DIChannels
	  section.data(2).logicalSrcIdx = 65;
	  section.data(2).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOChannels
	  section.data(3).logicalSrcIdx = 66;
	  section.data(3).dtTransOffset = 37;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_EIChannels
	  section.data(4).logicalSrcIdx = 67;
	  section.data(4).dtTransOffset = 41;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_EIQuadrature
	  section.data(5).logicalSrcIdx = 68;
	  section.data(5).dtTransOffset = 43;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POChannels
	  section.data(6).logicalSrcIdx = 69;
	  section.data(6).dtTransOffset = 44;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_OOChannels
	  section.data(7).logicalSrcIdx = 70;
	  section.data(7).dtTransOffset = 46;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 37;
      section.data(37)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 71;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 72;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 73;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 74;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 75;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 76;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 77;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 78;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 79;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 80;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 81;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 82;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 83;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 84;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 85;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 86;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 87;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 88;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 89;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 90;
	  section.data(20).dtTransOffset = 19;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 91;
	  section.data(21).dtTransOffset = 20;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 92;
	  section.data(22).dtTransOffset = 21;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 93;
	  section.data(23).dtTransOffset = 22;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 94;
	  section.data(24).dtTransOffset = 23;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 95;
	  section.data(25).dtTransOffset = 24;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 96;
	  section.data(26).dtTransOffset = 25;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 97;
	  section.data(27).dtTransOffset = 26;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 98;
	  section.data(28).dtTransOffset = 27;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 99;
	  section.data(29).dtTransOffset = 28;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 100;
	  section.data(30).dtTransOffset = 29;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 101;
	  section.data(31).dtTransOffset = 30;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 102;
	  section.data(32).dtTransOffset = 31;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 103;
	  section.data(33).dtTransOffset = 32;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 104;
	  section.data(34).dtTransOffset = 33;
	
	  ;% QBot2e_Forward_Kinematics_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 105;
	  section.data(35).dtTransOffset = 34;
	
	  ;% QBot2e_Forward_Kinematics_P.HILRead1_Active
	  section.data(36).logicalSrcIdx = 106;
	  section.data(36).dtTransOffset = 35;
	
	  ;% QBot2e_Forward_Kinematics_P.HILWrite_Active
	  section.data(37).logicalSrcIdx = 107;
	  section.data(37).dtTransOffset = 36;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_P.EnableSwitch_CurrentSetting
	  section.data(1).logicalSrcIdx = 108;
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
    nTotSects     = 6;
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
    ;% Auto data (QBot2e_Forward_Kinematics_B)
    ;%
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_B.HILRead1_o4
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_B.Product
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_B.Product1
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Forward_Kinematics_B.Product1_i
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Forward_Kinematics_B.Product1_g
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Forward_Kinematics_B.mmtom
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Forward_Kinematics_B.x0
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_B.Product_a
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Forward_Kinematics_B.mmtom_n
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Forward_Kinematics_B.x0_l
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Forward_Kinematics_B.Product_n
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Forward_Kinematics_B.x0_n
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Forward_Kinematics_B.Product_i
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Forward_Kinematics_B.VVavg
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Forward_Kinematics_B.Vin
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Forward_Kinematics_B.Constant
	  section.data(16).logicalSrcIdx = 15;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Forward_Kinematics_B.Count
	  section.data(17).logicalSrcIdx = 16;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2e_Forward_Kinematics_B.Sum
	  section.data(18).logicalSrcIdx = 17;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2e_Forward_Kinematics_B.div
	  section.data(19).logicalSrcIdx = 18;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2e_Forward_Kinematics_B.x_dot
	  section.data(20).logicalSrcIdx = 19;
	  section.data(20).dtTransOffset = 19;
	
	  ;% QBot2e_Forward_Kinematics_B.y_dot
	  section.data(21).logicalSrcIdx = 20;
	  section.data(21).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_KinematicsVfWtox_dot_d.x_dot
	  section.data(1).logicalSrcIdx = 22;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_KinematicsVfWtox_dot_d.y_dot
	  section.data(2).logicalSrcIdx = 23;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_KinematicsVfWtox_dot_d.psi_dot
	  section.data(3).logicalSrcIdx = 24;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_Diff_Drive_Kinematic_c.vC
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_Diff_Drive_Kinematic_c.Omega
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_Diff_Drive_Kinematic_h.vC
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_Diff_Drive_Kinematic_h.Omega
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_KinematicsVfWtox_doty_.x_dot
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_KinematicsVfWtox_doty_.y_dot
	  section.data(2).logicalSrcIdx = 30;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_KinematicsVfWtox_doty_.psi_dot
	  section.data(3).logicalSrcIdx = 31;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_Diff_Drive_Kinematics.vC
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_B.sf_Qbot2_Diff_Drive_Kinematics.Omega
	  section.data(2).logicalSrcIdx = 33;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(6) = section;
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
    sectIdxOffset = 6;
    
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
    ;% Auto data (QBot2e_Forward_Kinematics_DW)
    ;%
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_DW.Sumk1n1xk_DSTATE
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 4;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 8;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILWrite_OtherBuffer
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 12;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 7;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 17;
      section.data(17)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_DW.HILRead1_PWORK
	  section.data(1).logicalSrcIdx = 8;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_DW.Omega_0_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 9;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_DW.Omega_1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 10;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Forward_Kinematics_DW.Omega_2_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 11;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Forward_Kinematics_DW.Theta_dot_0_PWORK.LoggedData
	  section.data(5).logicalSrcIdx = 12;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Forward_Kinematics_DW.Theta_dot_1_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 13;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Forward_Kinematics_DW.Theta_dot_2_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 14;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_DW.vC_0_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 15;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Forward_Kinematics_DW.vC_1_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 16;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Forward_Kinematics_DW.vC_2_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 17;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Forward_Kinematics_DW.x_dot_0_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 18;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Forward_Kinematics_DW.x_dot_1_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 19;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Forward_Kinematics_DW.x_dot_2_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 20;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Forward_Kinematics_DW.y_dot_0_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 21;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Forward_Kinematics_DW.y_dot_1_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 22;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Forward_Kinematics_DW.y_dot_2_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 23;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILWrite_PWORK
	  section.data(17).logicalSrcIdx = 24;
	  section.data(17).dtTransOffset = 16;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 25;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 26;
	  section.data(2).dtTransOffset = 4;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 27;
	  section.data(3).dtTransOffset = 6;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 28;
	  section.data(4).dtTransOffset = 8;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 29;
	  section.data(5).dtTransOffset = 10;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 30;
	  section.data(6).dtTransOffset = 12;
	
	  ;% QBot2e_Forward_Kinematics_DW.HILRead1_EncoderBuffer
	  section.data(7).logicalSrcIdx = 31;
	  section.data(7).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_DW.Integrator1_IWORK
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_DW.Integrator1_IWORK_l
	  section.data(2).logicalSrcIdx = 34;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_DW.Integrator1_IWORK_p
	  section.data(3).logicalSrcIdx = 35;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_DW.SwitchCase_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 36;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(2).logicalSrcIdx = 37;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Forward_Kinematics_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(3).logicalSrcIdx = 38;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Forward_Kinematics_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(4).logicalSrcIdx = 39;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Forward_Kinematics_DW.EnabledMovingAverage_SubsysRanB
	  section.data(5).logicalSrcIdx = 40;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Forward_Kinematics_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 41;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Forward_Kinematics_DW.EnabledMovingAverage_MODE
	  section.data(2).logicalSrcIdx = 42;
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


  targMap.checksum0 = 1109575843;
  targMap.checksum1 = 3277952577;
  targMap.checksum2 = 658938219;
  targMap.checksum3 = 1026057266;

