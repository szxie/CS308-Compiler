; 声明string常量作为全局常量
@.LC0 = internal constant [13 x i8] c"hello world\0A\00"          ; [13 x i8]*
; puts函数的外部声明
declare i32 @puts(i8 *)                                           ; i32(i8 *)*
; main函数的定义
define i32 @main() {                                              ; i32()*
        ; Convert [13 x i8]* to i8  *...
        %cast210 = getelementptr [13 x i8]* @.LC0, i64 0, i64 0   ; i8 *
        ; Call puts function to write out the string to stdout...
        call i32 @puts(i8 * %cast210)                             ; i32
        ret i32 0
}
