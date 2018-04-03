# 2018-MUSI6106-Assignment2


Test case 1: using unit impulse as test signal, without any parameter

```
Testing FIR:
output:(print only one channel)
	1,0,0,0,0,0,0,0,0,0,0.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 expected:
	1,0,0,0,0,0,0,0,0,0,0.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 Testing IIR:
 output:(print only one channel)
	1,0,0,0,0,0,0,0,0,0,0.5,0,0,0,0,0,0,0,0,0,0.25,0,0,0,0,0,0,0,0,0
 expected:
	1,0,0,0,0,0,0,0,0,0,0.5,0,0,0,0,0,0,0,0,0,0.25,0,0,0,0,0,0,0,0,0
```

Test case 2: using unit impulse as test signal, with gain >= 1

```
Testing FIR (we allow gain >=1 in FIR):
 output:(print only one channel)
	1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 expected:
	1,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 Testing IIR (gain >=1 not allowed in IIR):
 output:(print only one channel)
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 expected:
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
```
Test case 3: using unit impulse as test signal, with negative Delay
```
Testing FIR:
 output:(print only one channel)
	1.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 expected:
	1.5,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 Testing IIR:
 output:(print only one channel)
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
 expected:
	1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0

```
