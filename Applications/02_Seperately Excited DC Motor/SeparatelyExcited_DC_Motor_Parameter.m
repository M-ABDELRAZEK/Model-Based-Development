%% Equations in Time Domain
% Va = ia * Ra + La * (di/dt) + Eb
% Eb = K * phi * w
% Tm = K * phi * ia = TL + Tr + J * (dw/dt)
% Tm = K * phi * ia = TL + B * w + J * (dw/dt)

% Va ==> Armature Voltage Applied To The Motor.
% ia ==> The Armature Current Flowing Through The Motor.
% Ra ==> The Resistance of The Armature Circuit.
% La ==> The Inductance of The Armature Winding.
% Eb ==> The Back Electromotive Force (EMF) Generated in The Motor.
% phi ==> The Magnetic Flux Produced By The Field Winding (Constant Because The Excitation Current is Constant).
% w ==> The Angular Velocity of The Motor's Rotor.
% K ==> Constant Depends On The Consruction of The Motor.
% Tm ==> The Electromagnetic Torque Produced By The Motor.
% TL ==> The Load Torque Opposing The Motor's Motion.
% Tr ==> Tourque Produced By Friction Opposing The Motor's Motion.
% J ==> The Moment of Inertia of The Motor's Rotor.
% B ==> Constant Depends On The Consruction of The Motor.

%% Equations in S Domain (Laplace)
% Va(s) = Ia(s) * Ra + La * (Ia(s) * s) + Eb(s)
% Ia(s) = (Va(s) - Eb(s)) / (Ra + La * s) ==> Transfer Function 1
% Tm(s) = TL(s) + B * w(s) + J * (w(s) * s)
% W(s) = (Tm(s) - TL(s)) / (B + J * s) ==> Transfer Function 2
% Eb(s) = K * phi * W(s)
% Tm = K * phi * Ia(s) 

%% Paramers Difinitions
Va = 200;
Ra = .5;
J = 5;
La = .1;
B = .01;
TL = 20;
Kphi = 1.6;

