#include <android/log.h>
#include "test_qihoo_com_jnicrash_CrashHandler.h"
#include "client/linux/handler/exception_handler.h"
#include "client/linux/handler/minidump_descriptor.h"

#include <jni.h>
#include <android/log.h>

#include <unistd.h>
#include <signal.h>
#include <string.h>
#include <assert.h>

#include <pthread.h>

#include <dlfcn.h>

#ifndef NDEBUG
#define Verify(x, r)  assert((x) && r)
#else
#define Verify(x, r)  ((void)(x))
#endif




//static bool dumpCallback(const google_breakpad::MinidumpDescriptor& descriptor,
//                         void* context,
//                         bool succeeded)
//{
//    __android_log_print(ANDROID_LOG_DEBUG, "NativeCrashHandler", "Dump path: %s=%d",  descriptor.path(), succeeded);
//    return succeeded;
//}

google_breakpad::ExceptionHandler* eh;

//void* crash_thread(void*) {
////    __android_log_print(ANDROID_LOG_DEBUG, "crash_thread", " activated");
//
//    sleep( 20);
//
//    int *p = 0;
//    *p = 1;
//
//    return 0;
//}

jint JNI_OnLoad(JavaVM *vm, void *reserved) {
    google_breakpad::MinidumpDescriptor descriptor("/mnt/sdcard/360dr/crash");
    eh = new google_breakpad::ExceptionHandler(descriptor, NULL, NULL, NULL, true, -1);
//    pthread_t thread;
//    pthread_create(&thread, NULL, &crash_thread, NULL);
//    pthread_join(thread, NULL);

//    __android_log_print(ANDROID_LOG_DEBUG, "NativeCrashHandler", "NativeCrashHandler activated");
    return JNI_VERSION_1_6;
}


//
//JNIEXPORT void JNICALL Java_test_qihoo_com_jnicrash_CrashHandler_test(JNIEnv *env, jobject obj)
//{
////    Java_com_shellware_nativecrashhandler_NativeCrashHandler_nRegisterForNativeCrash(env, obj);
//
//    int i = 0;
//    i++;
//    __android_log_print(ANDROID_LOG_INFO, "Java_test_qihoo_com_jnicrash_CrashHandler_test","aaa");
//
////    env->CallVoidMethod(applicationObject, makeCrashReportMethod, env->NewStringUTF("aaa"),
////                        NULL, (jint) gettid());
//
//
//    int* p = 0;
//    *p = 1;
//}
