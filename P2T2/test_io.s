@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1

declare i32 @__isoc99_scanf(i8*, ...)

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
	%x = alloca i32, align 4
	%call0 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %x)
	%0 = load i32* %x, align 4
	%call1 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32 %0)
	ret i32 0
}

