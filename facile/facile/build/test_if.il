.assembly test_if {}
.assembly extern mscorlib {}
.method static void Main()
{
.entrypoint
.maxstack 32
.locals init (int32 V_0, int32 V_1, int32 V_2)
call string class [mscorlib]System.Console::ReadLine()
call int32 int32::Parse(string)
stloc	0
ldloc	0
ldc.i4	0
cgt
brfalse	L_0001
ldloc	0
call void class [mscorlib]System.Console::WriteLine(int32)
br	L_0000
L_0001:
L_0000:
ldloc	0
ldc.i4	0
clt
ldc.i4	0
ceq
brfalse	L_0003
ldloc	0
call void class [mscorlib]System.Console::WriteLine(int32)
br	L_0002
L_0003:
ldc.i4	0
ldloc	0
sub
stloc	1
ldloc	1
call void class [mscorlib]System.Console::WriteLine(int32)
L_0002:
ldloc	0
ldc.i4	0
clt
brfalse	L_0005
ldc.i4	0
ldloc	0
sub
stloc	2
ldloc	2
call void class [mscorlib]System.Console::WriteLine(int32)
br	L_0004
L_0005:
ldloc	0
ldc.i4	0
ceq
brfalse	L_0006
ldloc	0
call void class [mscorlib]System.Console::WriteLine(int32)
br	L_0004
L_0006:
ldloc	0
call void class [mscorlib]System.Console::WriteLine(int32)
L_0004:
ret
}
