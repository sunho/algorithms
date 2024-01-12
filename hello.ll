; ModuleID = 'hello.ll'
source_filename = "hello.ll"
target datalayout = "e-m:o-p270:32:32-p271:32:32-p272:64:64-i64:64-f80:128-n8:16:32:64-S128"
target triple = "x86_64-apple-macosx13.0.0"

%objc_class = type { %objc_class*, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque* }
%swift.opaque = type opaque
%swift.method_descriptor = type { i32, i32 }
%T5hello10OldStudentC = type <{ %swift.refcounted, %TSi }>
%swift.refcounted = type { %swift.type*, i64 }
%swift.type = type { i64 }
%TSi = type <{ i64 }>
%swift.method_override_descriptor = type { i32, i32, i32 }
%T5hello10NewStudentC = type <{ %swift.refcounted, %TSi, %TSi }>
%swift.type_metadata_record = type { i32 }
%"$s5hello10OldStudentC10studentFeeSivM.Frame" = type { [24 x i8] }
%"$s5hello10NewStudentC6amountSivM.Frame" = type { [24 x i8] }
%swift.metadata_response = type { %swift.type*, i64 }

@"$s5hello10OldStudentC10studentFeeSivpWvd" = hidden constant i64 16, align 8
@"$sBoWV" = external global i8*, align 8
@"$s5hello10OldStudentCMm" = hidden global %objc_class { %objc_class* @"OBJC_METACLASS_$__TtCs12_SwiftObject", %objc_class* @"OBJC_METACLASS_$__TtCs12_SwiftObject", %swift.opaque* @_objc_empty_cache, %swift.opaque* null, %swift.opaque* bitcast ({ i32, i32, i32, i32, i8*, i8*, i8*, i8*, i8*, i8*, i8* }* @_METACLASS_DATA__TtC5hello10OldStudent to %swift.opaque*) }, align 8
@"OBJC_CLASS_$__TtCs12_SwiftObject" = external global %objc_class, align 8
@_objc_empty_cache = external global %swift.opaque
@"OBJC_METACLASS_$__TtCs12_SwiftObject" = external global %objc_class, align 8
@.str.22._TtC5hello10OldStudent = private unnamed_addr constant [23 x i8] c"_TtC5hello10OldStudent\00"
@_METACLASS_DATA__TtC5hello10OldStudent = internal constant { i32, i32, i32, i32, i8*, i8*, i8*, i8*, i8*, i8*, i8* } { i32 129, i32 40, i32 40, i32 0, i8* null, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.22._TtC5hello10OldStudent, i64 0, i64 0), i8* null, i8* null, i8* null, i8* null, i8* null }, section "__DATA, __objc_const", align 8
@.str.10.studentFee = private unnamed_addr constant [11 x i8] c"studentFee\00"
@.str.0. = private unnamed_addr constant [1 x i8] zeroinitializer
@_IVARS__TtC5hello10OldStudent = internal constant { i32, i32, [1 x { i64*, i8*, i8*, i32, i32 }] } { i32 32, i32 1, [1 x { i64*, i8*, i8*, i32, i32 }] [{ i64*, i8*, i8*, i32, i32 } { i64* @"$s5hello10OldStudentC10studentFeeSivpWvd", i8* getelementptr inbounds ([11 x i8], [11 x i8]* @.str.10.studentFee, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8], [1 x i8]* @.str.0., i64 0, i64 0), i32 3, i32 8 }] }, section "__DATA, __objc_const", align 8
@_DATA__TtC5hello10OldStudent = internal constant { i32, i32, i32, i32, i8*, i8*, i8*, i8*, { i32, i32, [1 x { i64*, i8*, i8*, i32, i32 }] }*, i8*, i8* } { i32 128, i32 16, i32 24, i32 0, i8* null, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.22._TtC5hello10OldStudent, i64 0, i64 0), i8* null, i8* null, { i32, i32, [1 x { i64*, i8*, i8*, i32, i32 }] }* @_IVARS__TtC5hello10OldStudent, i8* null, i8* null }, section "__DATA, __objc_const", align 8
@.str.5.hello = private constant [6 x i8] c"hello\00"
@"$s5helloMXM" = linkonce_odr hidden constant <{ i32, i32, i32 }> <{ i32 0, i32 0, i32 trunc (i64 sub (i64 ptrtoint ([6 x i8]* @.str.5.hello to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32 }>, <{ i32, i32, i32 }>* @"$s5helloMXM", i32 0, i32 2) to i64)) to i32) }>, section "__TEXT,__const", align 4
@.str.10.OldStudent = private constant [11 x i8] c"OldStudent\00"
@"$s5hello10OldStudentCMn" = hidden constant <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }> <{ i32 -2147483568, i32 trunc (i64 sub (i64 ptrtoint (<{ i32, i32, i32 }>* @"$s5helloMXM" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 1) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint ([11 x i8]* @.str.10.OldStudent to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 2) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint (%swift.metadata_response (i64)* @"$s5hello10OldStudentCMa" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 3) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint ({ i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10OldStudentCMF" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 4) to i64)) to i32), i32 0, i32 2, i32 16, i32 6, i32 1, i32 10, i32 11, i32 5, %swift.method_descriptor { i32 18, i32 trunc (i64 sub (i64 ptrtoint (i64 (%T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivg" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 13, i32 1) to i64)) to i32) }, %swift.method_descriptor { i32 19, i32 trunc (i64 sub (i64 ptrtoint (void (i64, %T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivs" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 14, i32 1) to i64)) to i32) }, %swift.method_descriptor { i32 20, i32 trunc (i64 sub (i64 ptrtoint ({ i8*, %TSi* } (i8*, %T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivM" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 15, i32 1) to i64)) to i32) }, %swift.method_descriptor { i32 18, i32 trunc (i64 sub (i64 ptrtoint (i64 (%T5hello10OldStudentC*)* @"$s5hello10OldStudentC3FeeSivg" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 16, i32 1) to i64)) to i32) }, %swift.method_descriptor { i32 1, i32 trunc (i64 sub (i64 ptrtoint (%T5hello10OldStudentC* (%swift.type*)* @"$s5hello10OldStudentCACycfC" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 17, i32 1) to i64)) to i32) } }>, section "__TEXT,__const", align 4
@"$s5hello10OldStudentCMf" = internal global <{ void (%T5hello10OldStudentC*)*, i8**, i64, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)*, %T5hello10OldStudentC* (%swift.type*)* }> <{ void (%T5hello10OldStudentC*)* @"$s5hello10OldStudentCfD", i8** @"$sBoWV", i64 ptrtoint (%objc_class* @"$s5hello10OldStudentCMm" to i64), %objc_class* @"OBJC_CLASS_$__TtCs12_SwiftObject", %swift.opaque* @_objc_empty_cache, %swift.opaque* null, %swift.opaque* bitcast (i8* getelementptr (i8, i8* bitcast ({ i32, i32, i32, i32, i8*, i8*, i8*, i8*, { i32, i32, [1 x { i64*, i8*, i8*, i32, i32 }] }*, i8*, i8* }* @_DATA__TtC5hello10OldStudent to i8*), i64 2) to %swift.opaque*), i32 2, i32 0, i32 24, i16 7, i16 0, i32 144, i32 16, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i8* null, i64 16, i64 (%T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivg", void (i64, %T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivs", { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivM", i64 (%T5hello10OldStudentC*)* @"$s5hello10OldStudentC3FeeSivg", %T5hello10OldStudentC* (%swift.type*)* @"$s5hello10OldStudentCACycfC" }>, align 8
@"symbolic _____ 5hello10OldStudentC" = linkonce_odr hidden constant <{ i8, i32, i8 }> <{ i8 1, i32 trunc (i64 sub (i64 ptrtoint (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i8, i32, i8 }>, <{ i8, i32, i8 }>* @"symbolic _____ 5hello10OldStudentC", i32 0, i32 1) to i64)) to i32), i8 0 }>, section "__TEXT,__swift5_typeref, regular", align 2
@"symbolic Si" = linkonce_odr hidden constant <{ [2 x i8], i8 }> <{ [2 x i8] c"Si", i8 0 }>, section "__TEXT,__swift5_typeref, regular", align 2
@0 = private constant [11 x i8] c"studentFee\00", section "__TEXT,__swift5_reflstr, regular"
@"$s5hello10OldStudentCMF" = internal constant { i32, i32, i16, i16, i32, i32, i32, i32 } { i32 trunc (i64 sub (i64 ptrtoint (<{ i8, i32, i8 }>* @"symbolic _____ 5hello10OldStudentC" to i64), i64 ptrtoint ({ i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10OldStudentCMF" to i64)) to i32), i32 0, i16 1, i16 12, i32 1, i32 2, i32 trunc (i64 sub (i64 ptrtoint (<{ [2 x i8], i8 }>* @"symbolic Si" to i64), i64 ptrtoint (i32* getelementptr inbounds ({ i32, i32, i16, i16, i32, i32, i32, i32 }, { i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10OldStudentCMF", i32 0, i32 6) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint ([11 x i8]* @0 to i64), i64 ptrtoint (i32* getelementptr inbounds ({ i32, i32, i16, i16, i32, i32, i32, i32 }, { i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10OldStudentCMF", i32 0, i32 7) to i64)) to i32) }, section "__TEXT,__swift5_fieldmd, regular", align 4
@"$s5hello10NewStudentC6amountSivpWvd" = hidden constant i64 24, align 8
@"$s5hello10NewStudentCMm" = hidden global %objc_class { %objc_class* @"OBJC_METACLASS_$__TtCs12_SwiftObject", %objc_class* @"$s5hello10OldStudentCMm", %swift.opaque* @_objc_empty_cache, %swift.opaque* null, %swift.opaque* bitcast ({ i32, i32, i32, i32, i8*, i8*, i8*, i8*, i8*, i8*, i8* }* @_METACLASS_DATA__TtC5hello10NewStudent to %swift.opaque*) }, align 8
@.str.22._TtC5hello10NewStudent = private unnamed_addr constant [23 x i8] c"_TtC5hello10NewStudent\00"
@_METACLASS_DATA__TtC5hello10NewStudent = internal constant { i32, i32, i32, i32, i8*, i8*, i8*, i8*, i8*, i8*, i8* } { i32 129, i32 40, i32 40, i32 0, i8* null, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.22._TtC5hello10NewStudent, i64 0, i64 0), i8* null, i8* null, i8* null, i8* null, i8* null }, section "__DATA, __objc_const", align 8
@.str.6.amount = private unnamed_addr constant [7 x i8] c"amount\00"
@_IVARS__TtC5hello10NewStudent = internal constant { i32, i32, [1 x { i64*, i8*, i8*, i32, i32 }] } { i32 32, i32 1, [1 x { i64*, i8*, i8*, i32, i32 }] [{ i64*, i8*, i8*, i32, i32 } { i64* @"$s5hello10NewStudentC6amountSivpWvd", i8* getelementptr inbounds ([7 x i8], [7 x i8]* @.str.6.amount, i64 0, i64 0), i8* getelementptr inbounds ([1 x i8], [1 x i8]* @.str.0., i64 0, i64 0), i32 3, i32 8 }] }, section "__DATA, __objc_const", align 8
@_DATA__TtC5hello10NewStudent = internal constant { i32, i32, i32, i32, i8*, i8*, i8*, i8*, { i32, i32, [1 x { i64*, i8*, i8*, i32, i32 }] }*, i8*, i8* } { i32 128, i32 24, i32 32, i32 0, i8* null, i8* getelementptr inbounds ([23 x i8], [23 x i8]* @.str.22._TtC5hello10NewStudent, i64 0, i64 0), i8* null, i8* null, { i32, i32, [1 x { i64*, i8*, i8*, i32, i32 }] }* @_IVARS__TtC5hello10NewStudent, i8* null, i8* null }, section "__DATA, __objc_const", align 8
@.str.10.NewStudent = private constant [11 x i8] c"NewStudent\00"
@"$s5hello10NewStudentCMn" = hidden constant <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }> <{ i32 -1073741744, i32 trunc (i64 sub (i64 ptrtoint (<{ i32, i32, i32 }>* @"$s5helloMXM" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 1) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint ([11 x i8]* @.str.10.NewStudent to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 2) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint (%swift.metadata_response (i64)* @"$s5hello10NewStudentCMa" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 3) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint ({ i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10NewStudentCMF" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 4) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint (<{ i8, i32, i8 }>* @"symbolic _____ 5hello10OldStudentC" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 5) to i64)) to i32), i32 2, i32 20, i32 4, i32 1, i32 16, i32 17, i32 3, %swift.method_descriptor { i32 18, i32 trunc (i64 sub (i64 ptrtoint (i64 (%T5hello10NewStudentC*)* @"$s5hello10NewStudentC6amountSivg" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 13, i32 1) to i64)) to i32) }, %swift.method_descriptor { i32 19, i32 trunc (i64 sub (i64 ptrtoint (void (i64, %T5hello10NewStudentC*)* @"$s5hello10NewStudentC6amountSivs" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 14, i32 1) to i64)) to i32) }, %swift.method_descriptor { i32 20, i32 trunc (i64 sub (i64 ptrtoint ({ i8*, %TSi* } (i8*, %T5hello10NewStudentC*)* @"$s5hello10NewStudentC6amountSivM" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 15, i32 1) to i64)) to i32) }, i32 2, %swift.method_override_descriptor { i32 trunc (i64 sub (i64 ptrtoint (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 17, i32 0) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint (%swift.method_descriptor* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 16) to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 17, i32 1) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint (i64 (%T5hello10NewStudentC*)* @"$s5hello10NewStudentC3FeeSivg" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 17, i32 2) to i64)) to i32) }, %swift.method_override_descriptor { i32 trunc (i64 sub (i64 ptrtoint (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 18, i32 0) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint (%swift.method_descriptor* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 17) to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 18, i32 1) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint (%T5hello10NewStudentC* (%swift.type*)* @"$s5hello10NewStudentCACycfC" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 18, i32 2) to i64)) to i32) } }>, section "__TEXT,__const", align 4
@"$s5hello10NewStudentCMf" = internal global <{ void (%T5hello10NewStudentC*)*, i8**, i64, %swift.type*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10NewStudentC*)*, %T5hello10NewStudentC* (%swift.type*)*, i64, i64 (%T5hello10NewStudentC*)*, void (i64, %T5hello10NewStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10NewStudentC*)* }> <{ void (%T5hello10NewStudentC*)* @"$s5hello10NewStudentCfD", i8** @"$sBoWV", i64 ptrtoint (%objc_class* @"$s5hello10NewStudentCMm" to i64), %swift.type* bitcast (i64* getelementptr inbounds (<{ void (%T5hello10OldStudentC*)*, i8**, i64, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)*, %T5hello10OldStudentC* (%swift.type*)* }>, <{ void (%T5hello10OldStudentC*)*, i8**, i64, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)*, %T5hello10OldStudentC* (%swift.type*)* }>* @"$s5hello10OldStudentCMf", i32 0, i32 2) to %swift.type*), %swift.opaque* @_objc_empty_cache, %swift.opaque* null, %swift.opaque* bitcast (i8* getelementptr (i8, i8* bitcast ({ i32, i32, i32, i32, i8*, i8*, i8*, i8*, { i32, i32, [1 x { i64*, i8*, i8*, i32, i32 }] }*, i8*, i8* }* @_DATA__TtC5hello10NewStudent to i8*), i64 2) to %swift.opaque*), i32 2, i32 0, i32 32, i16 7, i16 0, i32 176, i32 16, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i8* null, i64 16, i64 (%T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivg", void (i64, %T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivs", { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)* @"$s5hello10OldStudentC10studentFeeSivM", i64 (%T5hello10NewStudentC*)* @"$s5hello10NewStudentC3FeeSivg", %T5hello10NewStudentC* (%swift.type*)* @"$s5hello10NewStudentCACycfC", i64 24, i64 (%T5hello10NewStudentC*)* @"$s5hello10NewStudentC6amountSivg", void (i64, %T5hello10NewStudentC*)* @"$s5hello10NewStudentC6amountSivs", { i8*, %TSi* } (i8*, %T5hello10NewStudentC*)* @"$s5hello10NewStudentC6amountSivM" }>, align 8
@"symbolic _____ 5hello10NewStudentC" = linkonce_odr hidden constant <{ i8, i32, i8 }> <{ i8 1, i32 trunc (i64 sub (i64 ptrtoint (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn" to i64), i64 ptrtoint (i32* getelementptr inbounds (<{ i8, i32, i8 }>, <{ i8, i32, i8 }>* @"symbolic _____ 5hello10NewStudentC", i32 0, i32 1) to i64)) to i32), i8 0 }>, section "__TEXT,__swift5_typeref, regular", align 2
@1 = private constant [7 x i8] c"amount\00", section "__TEXT,__swift5_reflstr, regular"
@"$s5hello10NewStudentCMF" = internal constant { i32, i32, i16, i16, i32, i32, i32, i32 } { i32 trunc (i64 sub (i64 ptrtoint (<{ i8, i32, i8 }>* @"symbolic _____ 5hello10NewStudentC" to i64), i64 ptrtoint ({ i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10NewStudentCMF" to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint (<{ i8, i32, i8 }>* @"symbolic _____ 5hello10OldStudentC" to i64), i64 ptrtoint (i32* getelementptr inbounds ({ i32, i32, i16, i16, i32, i32, i32, i32 }, { i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10NewStudentCMF", i32 0, i32 1) to i64)) to i32), i16 1, i16 12, i32 1, i32 2, i32 trunc (i64 sub (i64 ptrtoint (<{ [2 x i8], i8 }>* @"symbolic Si" to i64), i64 ptrtoint (i32* getelementptr inbounds ({ i32, i32, i16, i16, i32, i32, i32, i32 }, { i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10NewStudentCMF", i32 0, i32 6) to i64)) to i32), i32 trunc (i64 sub (i64 ptrtoint ([7 x i8]* @1 to i64), i64 ptrtoint (i32* getelementptr inbounds ({ i32, i32, i16, i16, i32, i32, i32, i32 }, { i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10NewStudentCMF", i32 0, i32 7) to i64)) to i32) }, section "__TEXT,__swift5_fieldmd, regular", align 4
@"$s5hello10OldStudentCHn" = private constant %swift.type_metadata_record { i32 trunc (i64 sub (i64 ptrtoint (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn" to i64), i64 ptrtoint (%swift.type_metadata_record* @"$s5hello10OldStudentCHn" to i64)) to i32) }, section "__TEXT, __swift5_types, regular", align 4
@"$s5hello10NewStudentCHn" = private constant %swift.type_metadata_record { i32 trunc (i64 sub (i64 ptrtoint (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn" to i64), i64 ptrtoint (%swift.type_metadata_record* @"$s5hello10NewStudentCHn" to i64)) to i32) }, section "__TEXT, __swift5_types, regular", align 4
@__swift_reflection_version = linkonce_odr hidden constant i16 3
@"objc_classes_$s5hello10OldStudentCN" = internal global i8* bitcast (%swift.type* @"$s5hello10OldStudentCN" to i8*), section "__DATA,__objc_classlist,regular,no_dead_strip", align 8
@"objc_classes_$s5hello10NewStudentCN" = internal global i8* bitcast (%swift.type* @"$s5hello10NewStudentCN" to i8*), section "__DATA,__objc_classlist,regular,no_dead_strip", align 8
@llvm.used = appending global [7 x i8*] [i8* bitcast ({ i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10OldStudentCMF" to i8*), i8* bitcast ({ i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10NewStudentCMF" to i8*), i8* bitcast (%swift.type_metadata_record* @"$s5hello10OldStudentCHn" to i8*), i8* bitcast (%swift.type_metadata_record* @"$s5hello10NewStudentCHn" to i8*), i8* bitcast (i16* @__swift_reflection_version to i8*), i8* bitcast (i8** @"objc_classes_$s5hello10OldStudentCN" to i8*), i8* bitcast (i8** @"objc_classes_$s5hello10NewStudentCN" to i8*)], section "llvm.metadata"
@llvm.compiler.used = appending global [12 x i8*] [i8* bitcast (%swift.method_descriptor* @"$s5hello10OldStudentC10studentFeeSivgTq" to i8*), i8* bitcast (%swift.method_descriptor* @"$s5hello10OldStudentC10studentFeeSivsTq" to i8*), i8* bitcast (%swift.method_descriptor* @"$s5hello10OldStudentC10studentFeeSivMTq" to i8*), i8* bitcast (%swift.method_descriptor* @"$s5hello10OldStudentC3FeeSivgTq" to i8*), i8* bitcast (%swift.method_descriptor* @"$s5hello10OldStudentCACycfCTq" to i8*), i8* bitcast (<{ void (%T5hello10OldStudentC*)*, i8**, i64, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)*, %T5hello10OldStudentC* (%swift.type*)* }>* @"$s5hello10OldStudentCMf" to i8*), i8* bitcast (%swift.type* @"$s5hello10OldStudentCN" to i8*), i8* bitcast (%swift.method_descriptor* @"$s5hello10NewStudentC6amountSivgTq" to i8*), i8* bitcast (%swift.method_descriptor* @"$s5hello10NewStudentC6amountSivsTq" to i8*), i8* bitcast (%swift.method_descriptor* @"$s5hello10NewStudentC6amountSivMTq" to i8*), i8* bitcast (<{ void (%T5hello10NewStudentC*)*, i8**, i64, %swift.type*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10NewStudentC*)*, %T5hello10NewStudentC* (%swift.type*)*, i64, i64 (%T5hello10NewStudentC*)*, void (i64, %T5hello10NewStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10NewStudentC*)* }>* @"$s5hello10NewStudentCMf" to i8*), i8* bitcast (%swift.type* @"$s5hello10NewStudentCN" to i8*)], section "llvm.metadata"

@"$s5hello10OldStudentC10studentFeeSivgTq" = hidden alias %swift.method_descriptor, getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 13)
@"$s5hello10OldStudentC10studentFeeSivsTq" = hidden alias %swift.method_descriptor, getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 14)
@"$s5hello10OldStudentC10studentFeeSivMTq" = hidden alias %swift.method_descriptor, getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 15)
@"$s5hello10OldStudentC3FeeSivgTq" = hidden alias %swift.method_descriptor, getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 16)
@"$s5hello10OldStudentCACycfCTq" = hidden alias %swift.method_descriptor, getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", i32 0, i32 17)
@"$s5hello10OldStudentCN" = hidden alias %swift.type, bitcast (i64* getelementptr inbounds (<{ void (%T5hello10OldStudentC*)*, i8**, i64, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)*, %T5hello10OldStudentC* (%swift.type*)* }>, <{ void (%T5hello10OldStudentC*)*, i8**, i64, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)*, %T5hello10OldStudentC* (%swift.type*)* }>* @"$s5hello10OldStudentCMf", i32 0, i32 2) to %swift.type*)
@"$s5hello10NewStudentC6amountSivgTq" = hidden alias %swift.method_descriptor, getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 13)
@"$s5hello10NewStudentC6amountSivsTq" = hidden alias %swift.method_descriptor, getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 14)
@"$s5hello10NewStudentC6amountSivMTq" = hidden alias %swift.method_descriptor, getelementptr inbounds (<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", i32 0, i32 15)
@"$s5hello10NewStudentCN" = hidden alias %swift.type, bitcast (i64* getelementptr inbounds (<{ void (%T5hello10NewStudentC*)*, i8**, i64, %swift.type*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10NewStudentC*)*, %T5hello10NewStudentC* (%swift.type*)*, i64, i64 (%T5hello10NewStudentC*)*, void (i64, %T5hello10NewStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10NewStudentC*)* }>, <{ void (%T5hello10NewStudentC*)*, i8**, i64, %swift.type*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10NewStudentC*)*, %T5hello10NewStudentC* (%swift.type*)*, i64, i64 (%T5hello10NewStudentC*)*, void (i64, %T5hello10NewStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10NewStudentC*)* }>* @"$s5hello10NewStudentCMf", i32 0, i32 2) to %swift.type*)

define hidden swiftcc i64 @"$s5hello10OldStudentC10studentFeeSivpfi"() #0 {
entry:
  ret i64 800
}

define hidden swiftcc i64 @"$s5hello10OldStudentC10studentFeeSivg"(%T5hello10OldStudentC* swiftself %0) #0 {
entry:
  %access-scratch = alloca [24 x i8], align 8
  %1 = getelementptr inbounds %T5hello10OldStudentC, %T5hello10OldStudentC* %0, i32 0, i32 1
  %2 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.start.p0i8(i64 -1, i8* %2)
  %3 = bitcast %TSi* %1 to i8*
  call void @swift_beginAccess(i8* %3, [24 x i8]* %access-scratch, i64 32, i8* null) #2
  %._value = getelementptr inbounds %TSi, %TSi* %1, i32 0, i32 0
  %4 = load i64, i64* %._value, align 8
  call void @swift_endAccess([24 x i8]* %access-scratch) #2
  %5 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.end.p0i8(i64 -1, i8* %5)
  ret i64 %4
}

; Function Attrs: argmemonly nocallback nofree nosync nounwind willreturn
declare void @llvm.lifetime.start.p0i8(i64 immarg, i8* nocapture) #1

; Function Attrs: nounwind
declare void @swift_beginAccess(i8*, [24 x i8]*, i64, i8*) #2

; Function Attrs: nounwind
declare void @swift_endAccess([24 x i8]*) #2

; Function Attrs: argmemonly nocallback nofree nosync nounwind willreturn
declare void @llvm.lifetime.end.p0i8(i64 immarg, i8* nocapture) #1

define hidden swiftcc void @"$s5hello10OldStudentC10studentFeeSivs"(i64 %0, %T5hello10OldStudentC* swiftself %1) #0 {
entry:
  %access-scratch = alloca [24 x i8], align 8
  %2 = getelementptr inbounds %T5hello10OldStudentC, %T5hello10OldStudentC* %1, i32 0, i32 1
  %3 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.start.p0i8(i64 -1, i8* %3)
  %4 = bitcast %TSi* %2 to i8*
  call void @swift_beginAccess(i8* %4, [24 x i8]* %access-scratch, i64 33, i8* null) #2
  %._value = getelementptr inbounds %TSi, %TSi* %2, i32 0, i32 0
  store i64 %0, i64* %._value, align 8
  call void @swift_endAccess([24 x i8]* %access-scratch) #2
  %5 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.end.p0i8(i64 -1, i8* %5)
  ret void
}

; Function Attrs: noinline
define hidden swiftcc { i8*, %TSi* } @"$s5hello10OldStudentC10studentFeeSivM"(i8* noalias dereferenceable(32) %0, %T5hello10OldStudentC* swiftself %1) #3 {
entry:
  %FramePtr = bitcast i8* %0 to %"$s5hello10OldStudentC10studentFeeSivM.Frame"*
  %access-scratch = getelementptr inbounds %"$s5hello10OldStudentC10studentFeeSivM.Frame", %"$s5hello10OldStudentC10studentFeeSivM.Frame"* %FramePtr, i32 0, i32 0
  %2 = getelementptr inbounds %T5hello10OldStudentC, %T5hello10OldStudentC* %1, i32 0, i32 1
  %3 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.start.p0i8(i64 -1, i8* %3)
  %4 = bitcast %TSi* %2 to i8*
  call void @swift_beginAccess(i8* %4, [24 x i8]* %access-scratch, i64 33, i8* null) #2
  %5 = bitcast void (i8*, i1)* @"$s5hello10OldStudentC10studentFeeSivM.resume.0" to i8*
  %6 = insertvalue { i8*, %TSi* } undef, i8* %5, 0
  %7 = insertvalue { i8*, %TSi* } %6, %TSi* %2, 1
  ret { i8*, %TSi* } %7
}

define internal swiftcc void @"$s5hello10OldStudentC10studentFeeSivM.resume.0"(i8* noalias nonnull align 8 dereferenceable(32) %0, i1 %1) #0 {
entryresume.0:
  %FramePtr = bitcast i8* %0 to %"$s5hello10OldStudentC10studentFeeSivM.Frame"*
  %vFrame = bitcast %"$s5hello10OldStudentC10studentFeeSivM.Frame"* %FramePtr to i8*
  %access-scratch = getelementptr inbounds %"$s5hello10OldStudentC10studentFeeSivM.Frame", %"$s5hello10OldStudentC10studentFeeSivM.Frame"* %FramePtr, i32 0, i32 0
  br i1 %1, label %4, label %2

2:                                                ; preds = %entryresume.0
  call void @swift_endAccess([24 x i8]* %access-scratch) #2
  %3 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.end.p0i8(i64 -1, i8* %3)
  br label %CoroEnd

4:                                                ; preds = %entryresume.0
  call void @swift_endAccess([24 x i8]* %access-scratch) #2
  %5 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.end.p0i8(i64 -1, i8* %5)
  br label %CoroEnd

CoroEnd:                                          ; preds = %2, %4
  ret void
}

define hidden swiftcc i64 @"$s5hello10OldStudentC3FeeSivg"(%T5hello10OldStudentC* swiftself %0) #0 {
entry:
  %self.debug = alloca %T5hello10OldStudentC*, align 8
  %1 = bitcast %T5hello10OldStudentC** %self.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %1, i8 0, i64 8, i1 false)
  store %T5hello10OldStudentC* %0, %T5hello10OldStudentC** %self.debug, align 8
  %2 = bitcast %T5hello10OldStudentC* %0 to %swift.type**
  %3 = load %swift.type*, %swift.type** %2, align 8
  %4 = bitcast %swift.type* %3 to i64 (%T5hello10OldStudentC*)**
  %5 = getelementptr inbounds i64 (%T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)** %4, i64 11
  %6 = load i64 (%T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)** %5, align 8, !invariant.load !32
  %7 = call swiftcc i64 %6(%T5hello10OldStudentC* swiftself %0)
  ret i64 %7
}

; Function Attrs: argmemonly nofree nounwind willreturn writeonly
declare void @llvm.memset.p0i8.i64(i8* nocapture writeonly, i8, i64, i1 immarg) #4

define hidden swiftcc %swift.refcounted* @"$s5hello10OldStudentCfd"(%T5hello10OldStudentC* swiftself %0) #0 {
entry:
  %self.debug = alloca %T5hello10OldStudentC*, align 8
  %1 = bitcast %T5hello10OldStudentC** %self.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %1, i8 0, i64 8, i1 false)
  store %T5hello10OldStudentC* %0, %T5hello10OldStudentC** %self.debug, align 8
  %2 = bitcast %T5hello10OldStudentC* %0 to %swift.refcounted*
  ret %swift.refcounted* %2
}

define hidden swiftcc void @"$s5hello10OldStudentCfD"(%T5hello10OldStudentC* swiftself %0) #0 {
entry:
  %self.debug = alloca %T5hello10OldStudentC*, align 8
  %1 = bitcast %T5hello10OldStudentC** %self.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %1, i8 0, i64 8, i1 false)
  store %T5hello10OldStudentC* %0, %T5hello10OldStudentC** %self.debug, align 8
  %2 = call swiftcc %swift.refcounted* @"$s5hello10OldStudentCfd"(%T5hello10OldStudentC* swiftself %0)
  %3 = bitcast %swift.refcounted* %2 to %T5hello10OldStudentC*
  %4 = bitcast %T5hello10OldStudentC* %3 to %swift.refcounted*
  call void @swift_deallocClassInstance(%swift.refcounted* %4, i64 24, i64 7) #2
  ret void
}

; Function Attrs: nounwind
declare void @swift_deallocClassInstance(%swift.refcounted*, i64, i64) #2

define hidden swiftcc %T5hello10OldStudentC* @"$s5hello10OldStudentCACycfC"(%swift.type* swiftself %0) #0 {
entry:
  %1 = call noalias %swift.refcounted* @swift_allocObject(%swift.type* %0, i64 24, i64 7) #2
  %2 = bitcast %swift.refcounted* %1 to %T5hello10OldStudentC*
  %3 = call swiftcc %T5hello10OldStudentC* @"$s5hello10OldStudentCACycfc"(%T5hello10OldStudentC* swiftself %2)
  ret %T5hello10OldStudentC* %3
}

; Function Attrs: nounwind
declare %swift.refcounted* @swift_allocObject(%swift.type*, i64, i64) #2

define hidden swiftcc %T5hello10OldStudentC* @"$s5hello10OldStudentCACycfc"(%T5hello10OldStudentC* swiftself %0) #0 {
entry:
  %self.debug = alloca %T5hello10OldStudentC*, align 8
  %1 = bitcast %T5hello10OldStudentC** %self.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %1, i8 0, i64 8, i1 false)
  store %T5hello10OldStudentC* %0, %T5hello10OldStudentC** %self.debug, align 8
  %2 = getelementptr inbounds %T5hello10OldStudentC, %T5hello10OldStudentC* %0, i32 0, i32 1
  %._value = getelementptr inbounds %TSi, %TSi* %2, i32 0, i32 0
  store i64 800, i64* %._value, align 8
  ret %T5hello10OldStudentC* %0
}

define hidden swiftcc i64 @"$s5hello10NewStudentC6amountSivpfi"() #0 {
entry:
  ret i64 1000
}

define hidden swiftcc i64 @"$s5hello10NewStudentC6amountSivg"(%T5hello10NewStudentC* swiftself %0) #0 {
entry:
  %access-scratch = alloca [24 x i8], align 8
  %1 = getelementptr inbounds %T5hello10NewStudentC, %T5hello10NewStudentC* %0, i32 0, i32 2
  %2 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.start.p0i8(i64 -1, i8* %2)
  %3 = bitcast %TSi* %1 to i8*
  call void @swift_beginAccess(i8* %3, [24 x i8]* %access-scratch, i64 32, i8* null) #2
  %._value = getelementptr inbounds %TSi, %TSi* %1, i32 0, i32 0
  %4 = load i64, i64* %._value, align 8
  call void @swift_endAccess([24 x i8]* %access-scratch) #2
  %5 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.end.p0i8(i64 -1, i8* %5)
  ret i64 %4
}

define hidden swiftcc void @"$s5hello10NewStudentC6amountSivs"(i64 %0, %T5hello10NewStudentC* swiftself %1) #0 {
entry:
  %access-scratch = alloca [24 x i8], align 8
  %2 = getelementptr inbounds %T5hello10NewStudentC, %T5hello10NewStudentC* %1, i32 0, i32 2
  %3 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.start.p0i8(i64 -1, i8* %3)
  %4 = bitcast %TSi* %2 to i8*
  call void @swift_beginAccess(i8* %4, [24 x i8]* %access-scratch, i64 33, i8* null) #2
  %._value = getelementptr inbounds %TSi, %TSi* %2, i32 0, i32 0
  store i64 %0, i64* %._value, align 8
  call void @swift_endAccess([24 x i8]* %access-scratch) #2
  %5 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.end.p0i8(i64 -1, i8* %5)
  ret void
}

; Function Attrs: noinline
define hidden swiftcc { i8*, %TSi* } @"$s5hello10NewStudentC6amountSivM"(i8* noalias dereferenceable(32) %0, %T5hello10NewStudentC* swiftself %1) #3 {
entry:
  %FramePtr = bitcast i8* %0 to %"$s5hello10NewStudentC6amountSivM.Frame"*
  %access-scratch = getelementptr inbounds %"$s5hello10NewStudentC6amountSivM.Frame", %"$s5hello10NewStudentC6amountSivM.Frame"* %FramePtr, i32 0, i32 0
  %2 = getelementptr inbounds %T5hello10NewStudentC, %T5hello10NewStudentC* %1, i32 0, i32 2
  %3 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.start.p0i8(i64 -1, i8* %3)
  %4 = bitcast %TSi* %2 to i8*
  call void @swift_beginAccess(i8* %4, [24 x i8]* %access-scratch, i64 33, i8* null) #2
  %5 = bitcast void (i8*, i1)* @"$s5hello10NewStudentC6amountSivM.resume.0" to i8*
  %6 = insertvalue { i8*, %TSi* } undef, i8* %5, 0
  %7 = insertvalue { i8*, %TSi* } %6, %TSi* %2, 1
  ret { i8*, %TSi* } %7
}

define internal swiftcc void @"$s5hello10NewStudentC6amountSivM.resume.0"(i8* noalias nonnull align 8 dereferenceable(32) %0, i1 %1) #0 {
entryresume.0:
  %FramePtr = bitcast i8* %0 to %"$s5hello10NewStudentC6amountSivM.Frame"*
  %vFrame = bitcast %"$s5hello10NewStudentC6amountSivM.Frame"* %FramePtr to i8*
  %access-scratch = getelementptr inbounds %"$s5hello10NewStudentC6amountSivM.Frame", %"$s5hello10NewStudentC6amountSivM.Frame"* %FramePtr, i32 0, i32 0
  br i1 %1, label %4, label %2

2:                                                ; preds = %entryresume.0
  call void @swift_endAccess([24 x i8]* %access-scratch) #2
  %3 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.end.p0i8(i64 -1, i8* %3)
  br label %CoroEnd

4:                                                ; preds = %entryresume.0
  call void @swift_endAccess([24 x i8]* %access-scratch) #2
  %5 = bitcast [24 x i8]* %access-scratch to i8*
  call void @llvm.lifetime.end.p0i8(i64 -1, i8* %5)
  br label %CoroEnd

CoroEnd:                                          ; preds = %2, %4
  ret void
}

define hidden swiftcc i64 @"$s5hello10NewStudentC3FeeSivg"(%T5hello10NewStudentC* swiftself %0) #0 {
entry:
  %self.debug = alloca %T5hello10NewStudentC*, align 8
  %1 = bitcast %T5hello10NewStudentC** %self.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %1, i8 0, i64 8, i1 false)
  store %T5hello10NewStudentC* %0, %T5hello10NewStudentC** %self.debug, align 8
  %2 = bitcast %T5hello10NewStudentC* %0 to %swift.refcounted*
  %3 = call %swift.refcounted* @swift_retain(%swift.refcounted* returned %2) #5
  %4 = bitcast %T5hello10NewStudentC* %0 to %T5hello10OldStudentC*
  %5 = call swiftcc i64 @"$s5hello10OldStudentC3FeeSivg"(%T5hello10OldStudentC* swiftself %4)
  call void bitcast (void (%swift.refcounted*)* @swift_release to void (%T5hello10OldStudentC*)*)(%T5hello10OldStudentC* %4) #2
  %6 = bitcast %T5hello10NewStudentC* %0 to %swift.type**
  %7 = load %swift.type*, %swift.type** %6, align 8
  %8 = bitcast %swift.type* %7 to i64 (%T5hello10NewStudentC*)**
  %9 = getelementptr inbounds i64 (%T5hello10NewStudentC*)*, i64 (%T5hello10NewStudentC*)** %8, i64 17
  %10 = load i64 (%T5hello10NewStudentC*)*, i64 (%T5hello10NewStudentC*)** %9, align 8, !invariant.load !32
  %11 = call swiftcc i64 %10(%T5hello10NewStudentC* swiftself %0)
  %12 = call { i64, i1 } @llvm.sadd.with.overflow.i64(i64 %5, i64 %11)
  %13 = extractvalue { i64, i1 } %12, 0
  %14 = extractvalue { i64, i1 } %12, 1
  %15 = call i1 @llvm.expect.i1(i1 %14, i1 false)
  br i1 %15, label %17, label %16

16:                                               ; preds = %entry
  ret i64 %13

17:                                               ; preds = %entry
  call void @llvm.trap()
  unreachable
}

; Function Attrs: nounwind willreturn
declare %swift.refcounted* @swift_retain(%swift.refcounted* returned) #5

; Function Attrs: nounwind
declare void @swift_release(%swift.refcounted*) #2

; Function Attrs: nocallback nofree nosync nounwind readnone speculatable willreturn
declare { i64, i1 } @llvm.sadd.with.overflow.i64(i64, i64) #6

; Function Attrs: nocallback nofree nosync nounwind readnone willreturn
declare i1 @llvm.expect.i1(i1, i1) #7

; Function Attrs: cold noreturn nounwind
declare void @llvm.trap() #8

define hidden swiftcc %T5hello10NewStudentC* @"$s5hello10NewStudentCACycfC"(%swift.type* swiftself %0) #0 {
entry:
  %1 = call noalias %swift.refcounted* @swift_allocObject(%swift.type* %0, i64 32, i64 7) #2
  %2 = bitcast %swift.refcounted* %1 to %T5hello10NewStudentC*
  %3 = call swiftcc %T5hello10NewStudentC* @"$s5hello10NewStudentCACycfc"(%T5hello10NewStudentC* swiftself %2)
  ret %T5hello10NewStudentC* %3
}

define hidden swiftcc %T5hello10NewStudentC* @"$s5hello10NewStudentCACycfc"(%T5hello10NewStudentC* swiftself %0) #0 {
entry:
  %1 = alloca %T5hello10NewStudentC*, align 8
  %2 = bitcast %T5hello10NewStudentC** %1 to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %2, i8 0, i64 8, i1 false)
  %3 = bitcast %T5hello10NewStudentC** %1 to i8*
  call void @llvm.lifetime.start.p0i8(i64 8, i8* %3)
  %4 = bitcast %T5hello10NewStudentC* %0 to %swift.refcounted*
  %5 = call %swift.refcounted* @swift_retain(%swift.refcounted* returned %4) #5
  store %T5hello10NewStudentC* %0, %T5hello10NewStudentC** %1, align 8
  %6 = getelementptr inbounds %T5hello10NewStudentC, %T5hello10NewStudentC* %0, i32 0, i32 2
  %._value = getelementptr inbounds %TSi, %TSi* %6, i32 0, i32 0
  store i64 1000, i64* %._value, align 8
  call void bitcast (void (%swift.refcounted*)* @swift_release to void (%T5hello10NewStudentC*)*)(%T5hello10NewStudentC* %0) #2
  %7 = load %T5hello10NewStudentC*, %T5hello10NewStudentC** %1, align 8
  %8 = bitcast %T5hello10NewStudentC* %7 to %T5hello10OldStudentC*
  %9 = call swiftcc %T5hello10OldStudentC* @"$s5hello10OldStudentCACycfc"(%T5hello10OldStudentC* swiftself %8)
  %10 = bitcast %T5hello10OldStudentC* %9 to %T5hello10NewStudentC*
  %11 = bitcast %T5hello10NewStudentC* %10 to %swift.refcounted*
  %12 = call %swift.refcounted* @swift_retain(%swift.refcounted* returned %11) #5
  store %T5hello10NewStudentC* %10, %T5hello10NewStudentC** %1, align 8
  %toDestroy = load %T5hello10NewStudentC*, %T5hello10NewStudentC** %1, align 8
  call void bitcast (void (%swift.refcounted*)* @swift_release to void (%T5hello10NewStudentC*)*)(%T5hello10NewStudentC* %toDestroy) #2
  %13 = bitcast %T5hello10NewStudentC** %1 to i8*
  call void @llvm.lifetime.end.p0i8(i64 8, i8* %13)
  ret %T5hello10NewStudentC* %10
}

define hidden swiftcc %swift.refcounted* @"$s5hello10NewStudentCfd"(%T5hello10NewStudentC* swiftself %0) #0 {
entry:
  %self.debug = alloca %T5hello10NewStudentC*, align 8
  %1 = bitcast %T5hello10NewStudentC** %self.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %1, i8 0, i64 8, i1 false)
  store %T5hello10NewStudentC* %0, %T5hello10NewStudentC** %self.debug, align 8
  %2 = bitcast %T5hello10NewStudentC* %0 to %T5hello10OldStudentC*
  %3 = call swiftcc %swift.refcounted* @"$s5hello10OldStudentCfd"(%T5hello10OldStudentC* swiftself %2)
  %4 = bitcast %swift.refcounted* %3 to %T5hello10NewStudentC*
  ret %swift.refcounted* %3
}

define hidden swiftcc void @"$s5hello10NewStudentCfD"(%T5hello10NewStudentC* swiftself %0) #0 {
entry:
  %self.debug = alloca %T5hello10NewStudentC*, align 8
  %1 = bitcast %T5hello10NewStudentC** %self.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %1, i8 0, i64 8, i1 false)
  store %T5hello10NewStudentC* %0, %T5hello10NewStudentC** %self.debug, align 8
  %2 = call swiftcc %swift.refcounted* @"$s5hello10NewStudentCfd"(%T5hello10NewStudentC* swiftself %0)
  %3 = bitcast %swift.refcounted* %2 to %T5hello10NewStudentC*
  %4 = bitcast %T5hello10NewStudentC* %3 to %swift.refcounted*
  call void @swift_deallocClassInstance(%swift.refcounted* %4, i64 32, i64 7) #2
  ret void
}

define hidden swiftcc i64 @"$s5hello2HiSiyF"() #0 {
entry:
  %newstudent.debug = alloca %T5hello10NewStudentC*, align 8
  %0 = bitcast %T5hello10NewStudentC** %newstudent.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %0, i8 0, i64 8, i1 false)
  %1 = call swiftcc %swift.metadata_response @"$s5hello10NewStudentCMa"(i64 0) #10
  %2 = extractvalue %swift.metadata_response %1, 0
  %3 = call swiftcc %T5hello10NewStudentC* @"$s5hello10NewStudentCACycfC"(%swift.type* swiftself %2)
  store %T5hello10NewStudentC* %3, %T5hello10NewStudentC** %newstudent.debug, align 8
  %4 = bitcast %T5hello10NewStudentC* %3 to %swift.type**
  %5 = load %swift.type*, %swift.type** %4, align 8
  %6 = bitcast %swift.type* %5 to i64 (%T5hello10NewStudentC*)**
  %7 = getelementptr inbounds i64 (%T5hello10NewStudentC*)*, i64 (%T5hello10NewStudentC*)** %6, i64 14
  %8 = load i64 (%T5hello10NewStudentC*)*, i64 (%T5hello10NewStudentC*)** %7, align 8, !invariant.load !32
  %9 = call swiftcc i64 %8(%T5hello10NewStudentC* swiftself %3)
  call void bitcast (void (%swift.refcounted*)* @swift_release to void (%T5hello10NewStudentC*)*)(%T5hello10NewStudentC* %3) #2
  ret i64 %9
}

; Function Attrs: noinline nounwind readnone
define hidden swiftcc %swift.metadata_response @"$s5hello10NewStudentCMa"(i64 %0) #9 {
entry:
  %1 = call %objc_class* @objc_opt_self(%objc_class* bitcast (i64* getelementptr inbounds (<{ void (%T5hello10NewStudentC*)*, i8**, i64, %swift.type*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10NewStudentC*)*, %T5hello10NewStudentC* (%swift.type*)*, i64, i64 (%T5hello10NewStudentC*)*, void (i64, %T5hello10NewStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10NewStudentC*)* }>, <{ void (%T5hello10NewStudentC*)*, i8**, i64, %swift.type*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10NewStudentC*)*, %T5hello10NewStudentC* (%swift.type*)*, i64, i64 (%T5hello10NewStudentC*)*, void (i64, %T5hello10NewStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10NewStudentC*)* }>* @"$s5hello10NewStudentCMf", i32 0, i32 2) to %objc_class*)) #2
  %2 = bitcast %objc_class* %1 to %swift.type*
  %3 = insertvalue %swift.metadata_response undef, %swift.type* %2, 0
  %4 = insertvalue %swift.metadata_response %3, i64 0, 1
  ret %swift.metadata_response %4
}

define hidden swiftcc i64 @"$s5hello2HoSiyF"() #0 {
entry:
  %newstudent.debug = alloca %T5hello10NewStudentC*, align 8
  %0 = bitcast %T5hello10NewStudentC** %newstudent.debug to i8*
  call void @llvm.memset.p0i8.i64(i8* align 8 %0, i8 0, i64 8, i1 false)
  %1 = call swiftcc %swift.metadata_response @"$s5hello10NewStudentCMa"(i64 0) #10
  %2 = extractvalue %swift.metadata_response %1, 0
  %3 = call swiftcc %T5hello10NewStudentC* @"$s5hello10NewStudentCACycfC"(%swift.type* swiftself %2)
  store %T5hello10NewStudentC* %3, %T5hello10NewStudentC** %newstudent.debug, align 8
  %4 = bitcast %T5hello10NewStudentC* %3 to %swift.type**
  %5 = load %swift.type*, %swift.type** %4, align 8
  %6 = bitcast %swift.type* %5 to i64 (%T5hello10NewStudentC*)**
  %7 = getelementptr inbounds i64 (%T5hello10NewStudentC*)*, i64 (%T5hello10NewStudentC*)** %6, i64 17
  %8 = load i64 (%T5hello10NewStudentC*)*, i64 (%T5hello10NewStudentC*)** %7, align 8, !invariant.load !32
  %9 = call swiftcc i64 %8(%T5hello10NewStudentC* swiftself %3)
  call void bitcast (void (%swift.refcounted*)* @swift_release to void (%T5hello10NewStudentC*)*)(%T5hello10NewStudentC* %3) #2
  ret i64 %9
}

; Function Attrs: noinline nounwind readnone
define hidden swiftcc %swift.metadata_response @"$s5hello10OldStudentCMa"(i64 %0) #9 {
entry:
  %1 = call %objc_class* @objc_opt_self(%objc_class* bitcast (i64* getelementptr inbounds (<{ void (%T5hello10OldStudentC*)*, i8**, i64, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)*, %T5hello10OldStudentC* (%swift.type*)* }>, <{ void (%T5hello10OldStudentC*)*, i8**, i64, %objc_class*, %swift.opaque*, %swift.opaque*, %swift.opaque*, i32, i32, i32, i16, i16, i32, i32, <{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>*, i8*, i64, i64 (%T5hello10OldStudentC*)*, void (i64, %T5hello10OldStudentC*)*, { i8*, %TSi* } (i8*, %T5hello10OldStudentC*)*, i64 (%T5hello10OldStudentC*)*, %T5hello10OldStudentC* (%swift.type*)* }>* @"$s5hello10OldStudentCMf", i32 0, i32 2) to %objc_class*)) #2
  %2 = bitcast %objc_class* %1 to %swift.type*
  %3 = insertvalue %swift.metadata_response undef, %swift.type* %2, 0
  %4 = insertvalue %swift.metadata_response %3, i64 0, 1
  ret %swift.metadata_response %4
}

; Function Attrs: nounwind
declare %objc_class* @objc_opt_self(%objc_class*) #2

attributes #0 = { "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #1 = { argmemonly nocallback nofree nosync nounwind willreturn }
attributes #2 = { nounwind }
attributes #3 = { noinline "frame-pointer"="all" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #4 = { argmemonly nofree nounwind willreturn writeonly }
attributes #5 = { nounwind willreturn }
attributes #6 = { nocallback nofree nosync nounwind readnone speculatable willreturn }
attributes #7 = { nocallback nofree nosync nounwind readnone willreturn }
attributes #8 = { cold noreturn nounwind }
attributes #9 = { noinline nounwind readnone "frame-pointer"="none" "no-trapping-math"="true" "stack-protector-buffer-size"="8" "target-cpu"="penryn" "target-features"="+cx16,+cx8,+fxsr,+mmx,+sahf,+sse,+sse2,+sse3,+sse4.1,+ssse3,+x87" "tune-cpu"="generic" }
attributes #10 = { nounwind readnone }

!llvm.module.flags = !{!0, !1, !2, !3, !4, !5, !6, !7, !8, !9, !10, !11}
!swift.module.flags = !{!12}
!llvm.asan.globals = !{!13, !14, !15, !16, !17, !18, !19, !20, !21, !22, !23, !24, !25, !26}
!llvm.linker.options = !{!27, !28, !29, !30, !31}

!0 = !{i32 2, !"SDK Version", [2 x i32] [i32 13, i32 3]}
!1 = !{i32 1, !"Objective-C Version", i32 2}
!2 = !{i32 1, !"Objective-C Image Info Version", i32 0}
!3 = !{i32 1, !"Objective-C Image Info Section", !"__DATA,__objc_imageinfo,regular,no_dead_strip"}
!4 = !{i32 4, !"Objective-C Garbage Collection", i32 84412160}
!5 = !{i32 1, !"Objective-C Class Properties", i32 64}
!6 = !{i32 1, !"Objective-C Enforce ClassRO Pointer Signing", i8 0}
!7 = !{i32 1, !"wchar_size", i32 4}
!8 = !{i32 7, !"PIC Level", i32 2}
!9 = !{i32 7, !"uwtable", i32 2}
!10 = !{i32 7, !"frame-pointer", i32 2}
!11 = !{i32 1, !"Swift Version", i32 7}
!12 = !{!"standard-library", i1 false}
!13 = !{<{ i32, i32, i32 }>* @"$s5helloMXM", null, null, i1 false, i1 true}
!14 = !{<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor }>* @"$s5hello10OldStudentCMn", null, null, i1 false, i1 true}
!15 = !{<{ i8, i32, i8 }>* @"symbolic _____ 5hello10OldStudentC", null, null, i1 false, i1 true}
!16 = !{<{ [2 x i8], i8 }>* @"symbolic Si", null, null, i1 false, i1 true}
!17 = !{[11 x i8]* @0, null, null, i1 false, i1 true}
!18 = !{{ i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10OldStudentCMF", null, null, i1 false, i1 true}
!19 = !{<{ i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, i32, %swift.method_descriptor, %swift.method_descriptor, %swift.method_descriptor, i32, %swift.method_override_descriptor, %swift.method_override_descriptor }>* @"$s5hello10NewStudentCMn", null, null, i1 false, i1 true}
!20 = !{<{ i8, i32, i8 }>* @"symbolic _____ 5hello10NewStudentC", null, null, i1 false, i1 true}
!21 = !{[7 x i8]* @1, null, null, i1 false, i1 true}
!22 = !{{ i32, i32, i16, i16, i32, i32, i32, i32 }* @"$s5hello10NewStudentCMF", null, null, i1 false, i1 true}
!23 = !{%swift.type_metadata_record* @"$s5hello10OldStudentCHn", null, null, i1 false, i1 true}
!24 = !{%swift.type_metadata_record* @"$s5hello10NewStudentCHn", null, null, i1 false, i1 true}
!25 = !{i8** @"objc_classes_$s5hello10OldStudentCN", null, null, i1 false, i1 true}
!26 = !{i8** @"objc_classes_$s5hello10NewStudentCN", null, null, i1 false, i1 true}
!27 = !{!"-lswiftSwiftOnoneSupport"}
!28 = !{!"-lswiftCore"}
!29 = !{!"-lswift_Concurrency"}
!30 = !{!"-lswift_StringProcessing"}
!31 = !{!"-lobjc"}
!32 = !{}
