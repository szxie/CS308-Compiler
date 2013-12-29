@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1

@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @__isoc99_scanf(i8*, ...)

declare i32 @printf(i8*, ...)

define i32 @main() {
entry:
	%a = alloca i32, align 4
	%b = alloca i32, align 4
	%call0 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %a)
	%call1 = call i32 (i8*, ...)* @__isoc99_scanf(i8* getelementptr inbounds ([3 x i8]* @.str, i32 0, i32 0), i32* %b)
	%0 = load i32* %a, align 4
	%1 = load i32* %b, align 4
	%add0 = add nsw i32 %0, %1
	%call2 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %add0)
	ret i32 0
}
