; ModuleID = 'main'

@.str = private constant [4 x i8] c"%d\0A\00"

declare i32 @printf(i8*, ...)

define internal void @echo(i64 %toPrint) {
entry:
  %0 = call i32 (i8*, ...)* @printf(i8* getelementptr inbounds ([4 x i8]* @.str, i32 0, i32 0), i64 %toPrint)
  ret void
}

define internal void @main() {
entry:
  %0 = call i64 @do_math(i64 10)
  call void @echo(i64 %0)   
  ret void
}

define internal i64 @do_math(i64 %a1) {
entry:
  %a = alloca i64
  store i64 %a1, i64* %a
  %x = alloca i64
  %0 = load i64* %a
  %1 = mul i64 %0, 5
  %2 = add i64 %1, 3
  store i64 %2, i64* %x
  ret i64 %2
}

