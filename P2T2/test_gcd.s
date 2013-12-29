@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1

@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @__isoc99_scanf(i8*, ...)

declare i32 @printf(i8*, ...)

@a = common global i32 0, align 4
@b = common global i32 0, align 4

define i32 @gcd(i32 %x, i32 %y) {
entry:
	%x.addr = alloca i32, align 4
	store i32 %x, i32* %x.addr, align 4
	%y.addr = alloca i32, align 4
	store i32 %y, i32* %y.addr, align 4
	%0 = load i32* %y.addr, align 4
	%cmp0 = icmp eq i32 %0, 0
	br i1 %cmp0, label %if.then0, label %if.else0

if.then0:
	%1 = load i32* %x.addr, align 4
	ret i32 %1

if.else0:
	br label %if.end0

if.end0:
	%2 = load i32* %y.addr, align 4
	%3 = load i32* %x.addr, align 4
	%4 = load i32* %y.addr, align 4
	%rem0 = srem i32 %3, %4
	%call0 = call i32 @gcd(i32 %2, i32 %rem0)
	ret i32 %call0
}


define i32 @main() {
entry:
	%call0 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @a)
	%call1 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* @b)
	%0 = load i32* @a, align 4
	%1 = load i32* @b, align 4
	%call2 = call i32 @gcd(i32 %0, i32 %1)
	%call3 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %call2)
	ret i32 0
}

