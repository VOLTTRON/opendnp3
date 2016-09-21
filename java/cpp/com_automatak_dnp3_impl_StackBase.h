/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_automatak_dnp3_impl_StackBase */

#ifndef _Included_com_automatak_dnp3_impl_StackBase
#define _Included_com_automatak_dnp3_impl_StackBase
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_automatak_dnp3_impl_StackBase
 * Method:    add_native_stack_state_listener
 * Signature: (JLcom/automatak/dnp3/impl/StackStateProxy;)V
 */
JNIEXPORT void JNICALL Java_com_automatak_dnp3_impl_StackBase_add_1native_1stack_1state_1listener
  (JNIEnv *, jobject, jlong, jobject);

/*
 * Class:     com_automatak_dnp3_impl_StackBase
 * Method:    get_tcpclient_vto_endpoint
 * Signature: (JLjava/lang/String;ILjava/lang/String;IBJJZZ)J
 */
JNIEXPORT jlong JNICALL Java_com_automatak_dnp3_impl_StackBase_get_1tcpclient_1vto_1endpoint
  (JNIEnv *, jobject, jlong, jstring, jint, jstring, jint, jbyte, jlong, jlong, jboolean, jboolean);

/*
 * Class:     com_automatak_dnp3_impl_StackBase
 * Method:    get_tcpserver_vto_endpoint
 * Signature: (JLjava/lang/String;ILjava/lang/String;IBJJZZ)J
 */
JNIEXPORT jlong JNICALL Java_com_automatak_dnp3_impl_StackBase_get_1tcpserver_1vto_1endpoint
  (JNIEnv *, jobject, jlong, jstring, jint, jstring, jint, jbyte, jlong, jlong, jboolean, jboolean);

#ifdef __cplusplus
}
#endif
#endif
