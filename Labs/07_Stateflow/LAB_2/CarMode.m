classdef CarMode < Simulink.IntEnumType
    enumeration
        Acceleration(0)
        Deceleration(1)
        Stop(2)
        DoNothing(3)
        CruiseSystemOff(4)
        FaultOccured(5)
        Crash(6)
    end
end
