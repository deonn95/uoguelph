#include <stdio.h>
#include <stdlib.h>
#include "JNIlib.h"
#include "ParameterManager.h"

struct ParameterManager * p;

JNIEXPORT jint JNICALL Java_JNIlib_PM_1create(JNIEnv * env, jclass class, jint size){
	p = PM_create((int)size);
	if(p == NULL){
		return 0;
	}
	return 1;
}

JNIEXPORT jint JNICALL Java_JNIlib_PM_1destroy(JNIEnv * env, jclass class){
	return PM_destroy(p);
}

JNIEXPORT jint JNICALL Java_JNIlib_PM_1parseFrom(JNIEnv * env, jclass class, jstring fp, jchar comment){
	const char *str;
	int ret;
	FILE * f = fopen("temp.txt", "w");
	str = (*env)->GetStringUTFChars(env, fp, 0);
	fprintf(f, "%s", (char *)str);
	fclose(f);
	f = fopen("temp.txt", "r");
	ret = PM_parseFrom(p, f, comment);
	fclose(f);
	(*env)->ReleaseStringUTFChars(env, fp, str);
	return ret;
}

JNIEXPORT jint JNICALL Java_JNIlib_PM_1manage(JNIEnv * env, jclass class, jstring name, jint type, jint required){
	const char *str;
	int ret;
	param_t typ;
	if(type == 1){
		typ = INT_TYPE;
	}
	else if(type == 2){
		typ = REAL_TYPE;
	}
	else if(type == 3){
		typ = BOOLEAN_TYPE;
	}
	else if(type == 4){
		typ = STRING_TYPE;
	}
	else{
		typ = LIST_TYPE;
	}
	str = (char *) (*env)->GetStringUTFChars(env, name, NULL);
	ret = PM_manage(p, (char *)str, typ, (int) required);
	(*env)->ReleaseStringUTFChars(env, name, (char *)str);
	return (jint) ret;
}

JNIEXPORT jint JNICALL Java_JNIlib_hasValue(JNIEnv * env, jclass class, jstring name){
	const char *str;
	int ret;
	str = (*env)->GetStringUTFChars(env, name, 0);
	ret = PM_hasValue(p, (char *)str);
	(*env)->ReleaseStringUTFChars(env, name, str);
	return ret;
}

JNIEXPORT jstring JNICALL Java_JNIlib_getValue(JNIEnv *env, jclass class, jstring name, jint index){
	const char *str;
	char conv[100];
	str = (*env)->GetStringUTFChars(env, name, NULL);
	if(p->array[index].type == INT_TYPE){
		sprintf(conv, "%d", PM_getValue(p, (char *)str).int_val);
		return (*env)->NewStringUTF(env, conv);
	}
	else if(p->array[index].type == REAL_TYPE){
		sprintf(conv, "%f", PM_getValue(p, (char *)str).real_val);
		return (*env)->NewStringUTF(env, conv);
	}
	else if(p->array[index].type == BOOLEAN_TYPE){
		if(PM_getValue(p, (char*)str).bool_val == 1){
			return (*env)->NewStringUTF(env, "true");
		}
		return (*env)->NewStringUTF(env, "false");
	}
	else if(p->array[index].type == STRING_TYPE){
		return (*env)->NewStringUTF(env, PM_getValue(p, (char*)str).str_val);
	}
	
	return (*env)->NewStringUTF(env, "");
}

JNIEXPORT jint JNICALL Java_JNIlib_getListSize(JNIEnv * env, jclass class, jint index){
	return p->array[index].val.list_val->size;
}
