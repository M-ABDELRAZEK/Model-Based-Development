classdef (Enumeration) TPS_Modes < Simulink.IntEnumType
    enumeration
        Normal_Mode(0)
        Downgraded_Mode_Sen_1(1)
        Downgraded_Mode_Sen_2(2)
        Failure_Mode(3)
    end
end
