  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 10;
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
    ;% Auto data (QBot2e_Keyboard_Teleop_Wheel_P)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.BiasRemoval_end_time
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_input
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_inp_d
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_inp_j
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.SecondOrderLowPassFilter2_inp_n
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.XYFigure_maximum_x
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.XYFigure_maximum_y
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.XYFigure_minimum_x
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.XYFigure_minimum_y
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.BiasRemoval_start_time
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.BiasRemoval_switch_id
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.XYFigure_update_rate
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 7;
      section.data(7)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_analog_channels
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_digital_channels
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_encoder_channels
	  section.data(3).logicalSrcIdx = 14;
	  section.data(3).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_other_channels
	  section.data(4).logicalSrcIdx = 15;
	  section.data(4).dtTransOffset = 6;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILWrite_other_channels
	  section.data(5).logicalSrcIdx = 16;
	  section.data(5).dtTransOffset = 7;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_stream_index
	  section.data(6).logicalSrcIdx = 17;
	  section.data(6).dtTransOffset = 9;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_stream_index
	  section.data(7).logicalSrcIdx = 18;
	  section.data(7).dtTransOffset = 10;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DInitialize_active
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
      section.nData     = 66;
      section.data(66)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.unity_Value
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.UnitDelay_InitialCondition
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Sumk1n1xk_InitialCondition
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.zero_Y0
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Constant_Value
	  section.data(5).logicalSrcIdx = 24;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Vbiased_Y0
	  section.data(6).logicalSrcIdx = 25;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Vunbiased_Y0
	  section.data(7).logicalSrcIdx = 26;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Stepstart_time_Y0
	  section.data(8).logicalSrcIdx = 27;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Stepstart_time_YFinal
	  section.data(9).logicalSrcIdx = 28;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Stepend_time_Y0
	  section.data(10).logicalSrcIdx = 29;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Stepend_time_YFinal
	  section.data(11).logicalSrcIdx = 30;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOTerminate
	  section.data(12).logicalSrcIdx = 31;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOExit
	  section.data(13).logicalSrcIdx = 32;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOStart
	  section.data(14).logicalSrcIdx = 33;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOEnter
	  section.data(15).logicalSrcIdx = 34;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POFinal
	  section.data(16).logicalSrcIdx = 35;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOFinal
	  section.data(17).logicalSrcIdx = 36;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AIHigh
	  section.data(18).logicalSrcIdx = 37;
	  section.data(18).dtTransOffset = 20;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AILow
	  section.data(19).logicalSrcIdx = 38;
	  section.data(19).dtTransOffset = 26;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POFrequency
	  section.data(20).logicalSrcIdx = 39;
	  section.data(20).dtTransOffset = 32;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POInitial
	  section.data(21).logicalSrcIdx = 40;
	  section.data(21).dtTransOffset = 33;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOInitial
	  section.data(22).logicalSrcIdx = 41;
	  section.data(22).dtTransOffset = 34;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Integrator1_IC
	  section.data(23).logicalSrcIdx = 42;
	  section.data(23).dtTransOffset = 38;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Integrator2_IC
	  section.data(24).logicalSrcIdx = 43;
	  section.data(24).dtTransOffset = 39;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Integrator3_IC
	  section.data(25).logicalSrcIdx = 44;
	  section.data(25).dtTransOffset = 40;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Gain2_Gain
	  section.data(26).logicalSrcIdx = 45;
	  section.data(26).dtTransOffset = 41;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Gain5_Gain
	  section.data(27).logicalSrcIdx = 46;
	  section.data(27).dtTransOffset = 42;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Gain6_Gain
	  section.data(28).logicalSrcIdx = 47;
	  section.data(28).dtTransOffset = 43;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Gain4_Gain
	  section.data(29).logicalSrcIdx = 48;
	  section.data(29).dtTransOffset = 44;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.tickstoencoderrotation_Gain
	  section.data(30).logicalSrcIdx = 49;
	  section.data(30).dtTransOffset = 45;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.encoderrotationtowheelrotationg
	  section.data(31).logicalSrcIdx = 50;
	  section.data(31).dtTransOffset = 46;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.wheelradiousmm_Gain
	  section.data(32).logicalSrcIdx = 51;
	  section.data(32).dtTransOffset = 47;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.mmtom_Gain
	  section.data(33).logicalSrcIdx = 52;
	  section.data(33).dtTransOffset = 48;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Constant_Value_d
	  section.data(34).logicalSrcIdx = 53;
	  section.data(34).dtTransOffset = 49;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.x0_Value
	  section.data(35).logicalSrcIdx = 54;
	  section.data(35).dtTransOffset = 50;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Integrator2_IC_j
	  section.data(36).logicalSrcIdx = 55;
	  section.data(36).dtTransOffset = 51;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.tickstoencoderrotation_Gain_n
	  section.data(37).logicalSrcIdx = 56;
	  section.data(37).dtTransOffset = 52;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.encoderrotationtowheelrotatio_d
	  section.data(38).logicalSrcIdx = 57;
	  section.data(38).dtTransOffset = 53;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.wheelradiousmm_Gain_m
	  section.data(39).logicalSrcIdx = 58;
	  section.data(39).dtTransOffset = 54;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.mmtom_Gain_n
	  section.data(40).logicalSrcIdx = 59;
	  section.data(40).dtTransOffset = 55;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Constant_Value_p
	  section.data(41).logicalSrcIdx = 60;
	  section.data(41).dtTransOffset = 56;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.x0_Value_g
	  section.data(42).logicalSrcIdx = 61;
	  section.data(42).dtTransOffset = 57;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Integrator2_IC_jb
	  section.data(43).logicalSrcIdx = 62;
	  section.data(43).dtTransOffset = 58;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Integrator_IC
	  section.data(44).logicalSrcIdx = 63;
	  section.data(44).dtTransOffset = 59;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Brightness
	  section.data(45).logicalSrcIdx = 64;
	  section.data(45).dtTransOffset = 60;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Contrast
	  section.data(46).logicalSrcIdx = 65;
	  section.data(46).dtTransOffset = 61;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Hue
	  section.data(47).logicalSrcIdx = 66;
	  section.data(47).dtTransOffset = 62;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Saturation
	  section.data(48).logicalSrcIdx = 67;
	  section.data(48).dtTransOffset = 63;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Sharpness
	  section.data(49).logicalSrcIdx = 68;
	  section.data(49).dtTransOffset = 64;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Gamma
	  section.data(50).logicalSrcIdx = 69;
	  section.data(50).dtTransOffset = 65;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_WhiteBalance
	  section.data(51).logicalSrcIdx = 70;
	  section.data(51).dtTransOffset = 66;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_BacklightCompen
	  section.data(52).logicalSrcIdx = 71;
	  section.data(52).dtTransOffset = 67;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Gain
	  section.data(53).logicalSrcIdx = 72;
	  section.data(53).dtTransOffset = 68;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Exposure
	  section.data(54).logicalSrcIdx = 73;
	  section.data(54).dtTransOffset = 69;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Emitter
	  section.data(55).logicalSrcIdx = 74;
	  section.data(55).dtTransOffset = 70;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Brightness
	  section.data(56).logicalSrcIdx = 75;
	  section.data(56).dtTransOffset = 71;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Contrast
	  section.data(57).logicalSrcIdx = 76;
	  section.data(57).dtTransOffset = 72;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Hue
	  section.data(58).logicalSrcIdx = 77;
	  section.data(58).dtTransOffset = 73;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Saturation
	  section.data(59).logicalSrcIdx = 78;
	  section.data(59).dtTransOffset = 74;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Sharpness
	  section.data(60).logicalSrcIdx = 79;
	  section.data(60).dtTransOffset = 75;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Gamma
	  section.data(61).logicalSrcIdx = 80;
	  section.data(61).dtTransOffset = 76;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_WhiteBalance
	  section.data(62).logicalSrcIdx = 81;
	  section.data(62).dtTransOffset = 77;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_BacklightCompens
	  section.data(63).logicalSrcIdx = 82;
	  section.data(63).dtTransOffset = 78;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Gain
	  section.data(64).logicalSrcIdx = 83;
	  section.data(64).dtTransOffset = 79;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Exposure
	  section.data(65).logicalSrcIdx = 84;
	  section.data(65).dtTransOffset = 80;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Emitter
	  section.data(66).logicalSrcIdx = 85;
	  section.data(66).dtTransOffset = 81;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(5) = section;
      clear section
      
      section.nData     = 8;
      section.data(8)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIInitial
	  section.data(1).logicalSrcIdx = 86;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POModes
	  section.data(2).logicalSrcIdx = 87;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POConfiguration
	  section.data(3).logicalSrcIdx = 88;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POAlignment
	  section.data(4).logicalSrcIdx = 89;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POPolarity
	  section.data(5).logicalSrcIdx = 90;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostInitialize_SendBufferSize
	  section.data(6).logicalSrcIdx = 91;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostInitialize_ReceiveBufferSiz
	  section.data(7).logicalSrcIdx = 92;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostInitialize_ThreadPriority
	  section.data(8).logicalSrcIdx = 93;
	  section.data(8).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(6) = section;
      clear section
      
      section.nData     = 12;
      section.data(12)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Gain_Gain
	  section.data(1).logicalSrcIdx = 94;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AIChannels
	  section.data(2).logicalSrcIdx = 95;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DIChannels
	  section.data(3).logicalSrcIdx = 96;
	  section.data(3).dtTransOffset = 7;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOChannels
	  section.data(4).logicalSrcIdx = 97;
	  section.data(4).dtTransOffset = 38;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIChannels
	  section.data(5).logicalSrcIdx = 98;
	  section.data(5).dtTransOffset = 42;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIQuadrature
	  section.data(6).logicalSrcIdx = 99;
	  section.data(6).dtTransOffset = 44;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POChannels
	  section.data(7).logicalSrcIdx = 100;
	  section.data(7).dtTransOffset = 45;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOChannels
	  section.data(8).logicalSrcIdx = 101;
	  section.data(8).dtTransOffset = 47;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture1_Preset
	  section.data(9).logicalSrcIdx = 102;
	  section.data(9).dtTransOffset = 51;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.ImageCompress_Quality
	  section.data(10).logicalSrcIdx = 103;
	  section.data(10).dtTransOffset = 52;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.Video3DCapture_Preset
	  section.data(11).logicalSrcIdx = 104;
	  section.data(11).dtTransOffset = 53;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.ImageCompress_Quality_e
	  section.data(12).logicalSrcIdx = 105;
	  section.data(12).dtTransOffset = 54;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.rawdepthtomillimeter_Gain
	  section.data(1).logicalSrcIdx = 106;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(8) = section;
      clear section
      
      section.nData     = 44;
      section.data(44)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 107;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AOTerminate
	  section.data(2).logicalSrcIdx = 108;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AOExit
	  section.data(3).logicalSrcIdx = 109;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOTerminate
	  section.data(4).logicalSrcIdx = 110;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOExit
	  section.data(5).logicalSrcIdx = 111;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POTerminate
	  section.data(6).logicalSrcIdx = 112;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POExit
	  section.data(7).logicalSrcIdx = 113;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_CKPStart
	  section.data(8).logicalSrcIdx = 114;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_CKPEnter
	  section.data(9).logicalSrcIdx = 115;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_CKStart
	  section.data(10).logicalSrcIdx = 116;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_CKEnter
	  section.data(11).logicalSrcIdx = 117;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AIPStart
	  section.data(12).logicalSrcIdx = 118;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AIPEnter
	  section.data(13).logicalSrcIdx = 119;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AOPStart
	  section.data(14).logicalSrcIdx = 120;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AOPEnter
	  section.data(15).logicalSrcIdx = 121;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AOStart
	  section.data(16).logicalSrcIdx = 122;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AOEnter
	  section.data(17).logicalSrcIdx = 123;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_AOReset
	  section.data(18).logicalSrcIdx = 124;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOPStart
	  section.data(19).logicalSrcIdx = 125;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOPEnter
	  section.data(20).logicalSrcIdx = 126;
	  section.data(20).dtTransOffset = 19;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOStart
	  section.data(21).logicalSrcIdx = 127;
	  section.data(21).dtTransOffset = 20;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOEnter
	  section.data(22).logicalSrcIdx = 128;
	  section.data(22).dtTransOffset = 21;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOReset
	  section.data(23).logicalSrcIdx = 129;
	  section.data(23).dtTransOffset = 22;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIPStart
	  section.data(24).logicalSrcIdx = 130;
	  section.data(24).dtTransOffset = 23;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIPEnter
	  section.data(25).logicalSrcIdx = 131;
	  section.data(25).dtTransOffset = 24;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIStart
	  section.data(26).logicalSrcIdx = 132;
	  section.data(26).dtTransOffset = 25;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_EIEnter
	  section.data(27).logicalSrcIdx = 133;
	  section.data(27).dtTransOffset = 26;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POPStart
	  section.data(28).logicalSrcIdx = 134;
	  section.data(28).dtTransOffset = 27;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POPEnter
	  section.data(29).logicalSrcIdx = 135;
	  section.data(29).dtTransOffset = 28;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POStart
	  section.data(30).logicalSrcIdx = 136;
	  section.data(30).dtTransOffset = 29;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POEnter
	  section.data(31).logicalSrcIdx = 137;
	  section.data(31).dtTransOffset = 30;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_POReset
	  section.data(32).logicalSrcIdx = 138;
	  section.data(32).dtTransOffset = 31;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_OOReset
	  section.data(33).logicalSrcIdx = 139;
	  section.data(33).dtTransOffset = 32;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOFinal
	  section.data(34).logicalSrcIdx = 140;
	  section.data(34).dtTransOffset = 33;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILInitialize_DOInitial
	  section.data(35).logicalSrcIdx = 141;
	  section.data(35).dtTransOffset = 34;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostInitialize_RunClient
	  section.data(36).logicalSrcIdx = 142;
	  section.data(36).dtTransOffset = 35;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostInitialize_UseWindow
	  section.data(37).logicalSrcIdx = 143;
	  section.data(37).dtTransOffset = 36;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostInitialize_Active
	  section.data(38).logicalSrcIdx = 144;
	  section.data(38).dtTransOffset = 37;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILRead1_Active
	  section.data(39).logicalSrcIdx = 145;
	  section.data(39).dtTransOffset = 38;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_Enabled
	  section.data(40).logicalSrcIdx = 146;
	  section.data(40).dtTransOffset = 39;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_DebugMode
	  section.data(41).logicalSrcIdx = 147;
	  section.data(41).dtTransOffset = 40;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HILWrite_Active
	  section.data(42).logicalSrcIdx = 148;
	  section.data(42).dtTransOffset = 41;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.VideoDisplay_UseHardware
	  section.data(43).logicalSrcIdx = 149;
	  section.data(43).dtTransOffset = 42;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.VideoDisplay_UseHardware_c
	  section.data(44).logicalSrcIdx = 150;
	  section.data(44).dtTransOffset = 43;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(9) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostInitialize_URI
	  section.data(1).logicalSrcIdx = 151;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.XYFigure_Mode
	  section.data(2).logicalSrcIdx = 152;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_P.HostKeyboard_ScanCodes
	  section.data(3).logicalSrcIdx = 153;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(10) = section;
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
    ;% Auto data (QBot2e_Keyboard_Teleop_Wheel_B)
    ;%
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture1_o2
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture_o2
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
      section.nData     = 26;
      section.data(26)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.HILRead1_o1
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.HILRead1_o4
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Product
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Integrator1
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Integrator2
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Integrator3
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 5;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.mmtom
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 6;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.x0
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 7;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Product_f
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 8;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Product1
	  section.data(10).logicalSrcIdx = 11;
	  section.data(10).dtTransOffset = 9;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.mmtom_p
	  section.data(11).logicalSrcIdx = 12;
	  section.data(11).dtTransOffset = 10;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.x0_o
	  section.data(12).logicalSrcIdx = 13;
	  section.data(12).dtTransOffset = 11;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Product_d
	  section.data(13).logicalSrcIdx = 14;
	  section.data(13).dtTransOffset = 12;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Product1_n
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture1_o3
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture_o3
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 15;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.x_dot
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 16;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.y_dot
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 17;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.psi_dot
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 18;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Omega
	  section.data(20).logicalSrcIdx = 21;
	  section.data(20).dtTransOffset = 19;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.VVavg
	  section.data(21).logicalSrcIdx = 22;
	  section.data(21).dtTransOffset = 20;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Vin
	  section.data(22).logicalSrcIdx = 23;
	  section.data(22).dtTransOffset = 21;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Constant
	  section.data(23).logicalSrcIdx = 24;
	  section.data(23).dtTransOffset = 22;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Count
	  section.data(24).logicalSrcIdx = 25;
	  section.data(24).dtTransOffset = 23;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Sum
	  section.data(25).logicalSrcIdx = 26;
	  section.data(25).dtTransOffset = 24;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.div
	  section.data(26).logicalSrcIdx = 27;
	  section.data(26).dtTransOffset = 25;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Channel
	  section.data(1).logicalSrcIdx = 28;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Channel_i
	  section.data(2).logicalSrcIdx = 29;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.HostInitialize_o2
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(4) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture1_o1
	  section.data(1).logicalSrcIdx = 31;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(5) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.HostInitialize_o1
	  section.data(1).logicalSrcIdx = 32;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_B.Video3DCapture_o1
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
    nTotSects     = 15;
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
    ;% Auto data (QBot2e_Keyboard_Teleop_Wheel_DW)
    ;%
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_Lock
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_KeyboardState
	  section.data(1).logicalSrcIdx = 1;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.UnitDelay_DSTATE
	  section.data(1).logicalSrcIdx = 2;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Sumk1n1xk_DSTATE
	  section.data(2).logicalSrcIdx = 3;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_FilterFrequency
	  section.data(3).logicalSrcIdx = 4;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedFreqs
	  section.data(4).logicalSrcIdx = 5;
	  section.data(4).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POValues
	  section.data(5).logicalSrcIdx = 6;
	  section.data(5).dtTransOffset = 6;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_OOValues
	  section.data(6).logicalSrcIdx = 7;
	  section.data(6).dtTransOffset = 8;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.XYFigure_XBuffer
	  section.data(7).logicalSrcIdx = 8;
	  section.data(7).dtTransOffset = 12;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.XYFigure_YBuffer
	  section.data(8).logicalSrcIdx = 9;
	  section.data(8).dtTransOffset = 1012;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILWrite_OtherBuffer
	  section.data(9).logicalSrcIdx = 10;
	  section.data(9).dtTransOffset = 2012;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HostInitialize_ConnectedHandle
	  section.data(1).logicalSrcIdx = 11;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress
	  section.data(1).logicalSrcIdx = 12;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_Compress_b
	  section.data(2).logicalSrcIdx = 13;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Video3DInitialize_Video3D
	  section.data(1).logicalSrcIdx = 14;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture1_Video3D
	  section.data(2).logicalSrcIdx = 15;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture_Video3D
	  section.data(3).logicalSrcIdx = 16;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(6) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture1_Stream
	  section.data(1).logicalSrcIdx = 17;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Video3DCapture_Stream
	  section.data(2).logicalSrcIdx = 18;
	  section.data(2).dtTransOffset = 1;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(7) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 19;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(8) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILRead1_PWORK
	  section.data(1).logicalSrcIdx = 20;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILWrite_PWORK
	  section.data(2).logicalSrcIdx = 21;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK.Fifo
	  section.data(3).logicalSrcIdx = 22;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Channel_PWORK_n.Fifo
	  section.data(4).logicalSrcIdx = 23;
	  section.data(4).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(9) = section;
      clear section
      
      section.nData     = 9;
      section.data(9)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOStates
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_QuadratureModes
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_InitialEICounts
	  section.data(3).logicalSrcIdx = 26;
	  section.data(3).dtTransOffset = 6;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POModeValues
	  section.data(4).logicalSrcIdx = 27;
	  section.data(4).dtTransOffset = 8;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POAlignValues
	  section.data(5).logicalSrcIdx = 28;
	  section.data(5).dtTransOffset = 10;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POPolarityVals
	  section.data(6).logicalSrcIdx = 29;
	  section.data(6).dtTransOffset = 12;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILRead1_EncoderBuffer
	  section.data(7).logicalSrcIdx = 30;
	  section.data(7).dtTransOffset = 14;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_DIMS1
	  section.data(8).logicalSrcIdx = 31;
	  section.data(8).dtTransOffset = 16;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_DIMS1_g
	  section.data(9).logicalSrcIdx = 32;
	  section.data(9).dtTransOffset = 17;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(10) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_POSortedChans
	  section.data(1).logicalSrcIdx = 33;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(11) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.XYFigure_IWORK
	  section.data(1).logicalSrcIdx = 34;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Integrator1_IWORK
	  section.data(2).logicalSrcIdx = 35;
	  section.data(2).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.Integrator1_IWORK_o
	  section.data(3).logicalSrcIdx = 36;
	  section.data(3).dtTransOffset = 3;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(12) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCase_ActiveSubsystem
	  section.data(1).logicalSrcIdx = 37;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem2_Subs
	  section.data(2).logicalSrcIdx = 38;
	  section.data(2).dtTransOffset = 1;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem1_Subs
	  section.data(3).logicalSrcIdx = 39;
	  section.data(3).dtTransOffset = 2;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.SwitchCaseActionSubsystem_Subsy
	  section.data(4).logicalSrcIdx = 40;
	  section.data(4).dtTransOffset = 3;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_SubsysRanB
	  section.data(5).logicalSrcIdx = 41;
	  section.data(5).dtTransOffset = 4;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(13) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine
	  section.data(1).logicalSrcIdx = 42;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.ImageCompress_ScanLine_c
	  section.data(2).logicalSrcIdx = 43;
	  section.data(2).dtTransOffset = 5120;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(14) = section;
      clear section
      
      section.nData     = 4;
      section.data(4)  = dumData; %prealloc
      
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HILInitialize_DOBits
	  section.data(1).logicalSrcIdx = 44;
	  section.data(1).dtTransOffset = 0;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.XYFigure_IsFull
	  section.data(2).logicalSrcIdx = 45;
	  section.data(2).dtTransOffset = 4;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.HostKeyboard_NewData
	  section.data(3).logicalSrcIdx = 46;
	  section.data(3).dtTransOffset = 5;
	
	  ;% QBot2e_Keyboard_Teleop_Wheel_DW.EnabledMovingAverage_MODE
	  section.data(4).logicalSrcIdx = 47;
	  section.data(4).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(15) = section;
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


  targMap.checksum0 = 1827389757;
  targMap.checksum1 = 924461286;
  targMap.checksum2 = 3403631129;
  targMap.checksum3 = 4275206613;

