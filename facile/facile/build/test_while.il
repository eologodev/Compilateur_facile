.assembly test_while {}
.assembly extern mscorlib {}
.method static void Main()
{
.entrypoint
.maxstack 32
.locals init (int32 V_0, int32 V_1)
ldc.i4	1
stloc	0
L_0000:
ldloc	0
ldc.i4	5
cgt
ldc.i4	0
ceq
brfalse	L_0001
ldloc	0
call void class [mscorlib]System.Console::WriteLine(int32)
ldloc	0
ldc.i4	1
add
stloc	0
br	L_0000
L_0001:
ldc.i4	1
stloc	1
L_0002:
ldloc	1
ldc.i4	10
cgt
ldc.i4	0
ceq
brfalse	L_0003
ldloc	1
ldc.i4	3
cgt
brfalse	L_0005
br	L_0003
br	L_0004
L_0005:
L_0004:
ldloc	1
call void class [mscorlib]System.Console::WriteLine(int32)
ldloc	1
ldc.i4	1
add
stloc	1
br	L_0002
L_0003:
ret
}
