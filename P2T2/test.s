@.str = private unnamed_addr constant [3 x i8] c"%d\00", align 1

@.str1 = private unnamed_addr constant [4 x i8] c"%d\0A\00", align 1

declare i32 @__isoc99_scanf(i8*, ...)

declare i32 @printf(i8*, ...)


define i32 @main() {
entry:
	%sub0 = sub nsw i32 0, 215
	%call0 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str1, i32 0, i32 0), i32 %sub0)
	ret i32 0
}

