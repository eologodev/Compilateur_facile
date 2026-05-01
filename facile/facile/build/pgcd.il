.assembly pgcd {}
.assembly extern mscorlib {}
.method static void Main()
{
.entrypoint
.maxstack 32
.locals init (int32 V_0, int32 V_1)
call string class [mscorlib]System.Console::ReadLine()
call int32 int32::Parse(string)
stloc	0
call string class [mscorlib]System.Console::ReadLine()
call int32 int32::Parse(string)
stloc	1
L_0000:
ldloc	0
ldloc	1
ceq
ldc.i4	0
ceq
brfalse	L_0001
ldloc	0
ldloc	1
cgt
brfalse	L_0003
ldloc	0
ldloc	1
sub
stloc	0
br	L_0002
L_0003:
ldloc	1
ldloc	0
sub
stloc	1
L_0002:
br	L_0000
L_0001:
ldloc	0
call void class [mscorlib]System.Console::WriteLine(int32)
ret
}
