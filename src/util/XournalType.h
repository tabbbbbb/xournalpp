/*
 * Xournal++
 *
 * Type macros like GLib use for C to find wrong pointers at runtime
 *
 * @author Xournal Team
 * http://xournal.sf.net
 *
 * @license GPL
 */


#ifndef __XOURNALTYPE_H__
#define __XOURNALTYPE_H__

#define XOJ_MEMORY_CHECK_ENABLED

#ifdef XOJ_MEMORY_CHECK_ENABLED

#define XOJ_DECLARE_TYPE(type, id) \
	const int __XOJ_TYPE_ ## type = id

/**
 * This creates a Xournal mTypeinformation Attribute
 */
#define XOJ_TYPE_ATTRIB \
	int __xoj_type; \
	int __xoj_typeCheckvalue

/**
 * Initalize the Xournal type info, this should be called in the constructor
 */
#define XOJ_INIT_TYPE(type) \
		this->__xoj_type = __XOJ_TYPE_ ## type; \
		this->__xoj_typeCheckvalue = 0xFFAA00AA

/**
 * Release the Xournal type info, this should be called in the destructor
 */
#define XOJ_RELEASE_TYPE(type) \
		XOJ_CHECK_TYPE(type) \
		this->__xoj_type = -(__XOJ_TYPE_ ## type); \
		this->__xoj_typeCheckvalue = 0xFFAA00AA


/**
 * Checks the type of "this" and returns if "this" is not an instance of "name"
 */
#define XOJ_CHECK_TYPE_OBJ(obj, type) \
		if(obj == NULL) { \
			g_warning("XojTypeCheck failed: NULL %s:%i", __FILE__, __LINE__);\
		} \
		if(((type *)obj)->__xoj_typeCheckvalue != 0xFFAA00AA) { \
			g_warning("XojTypeCheck failed: expected %s but get something else on %s:%i", #type, __FILE__, __LINE__);\
		} \
		if(((type *)obj)->__xoj_type != __XOJ_TYPE_ ## type) { \
			g_warning("XojTypeCheck failed: expected %s but get %s on %s:%i", #type, xoj_type_getName(((type *)obj)->__xoj_type), __FILE__, __LINE__);\
		}

/**
 * Checks the type of "this" and returns if "this" is not an instance of "name"
 */
#define XOJ_CHECK_TYPE(type) \
		if(this == NULL) { \
			g_warning("XojTypeCheck failed: NULL %s:%i", __FILE__, __LINE__);\
		} \
		if(((type *)this)->__xoj_typeCheckvalue != 0xFFAA00AA) { \
			g_warning("XojTypeCheck failed: expected %s but get something else on %s:%i", #type, __FILE__, __LINE__);\
		} \
		if(((type *)this)->__xoj_type != __XOJ_TYPE_ ## type) { \
			g_warning("XojTypeCheck failed: expected %s but get %s on %s:%i", #type, xoj_type_getName(((type *)this)->__xoj_type), __FILE__, __LINE__);\
		}

const char * xoj_type_getName(int id);

#include "XournalTypeList.h"

#else

#define XOJ_DECLARE_TYPE(name, id)
#define XOJ_TYPE_ATTRIB
#define XOJ_INIT_TYPE(name)
#define XOJ_RELEASE_TYPE(name)
#define XOJ_CHECK_TYPE_OBJ(obj, name)
#define XOJ_CHECK_TYPE(name)

#endif


#endif /* __XOURNALTYPE_H__ */