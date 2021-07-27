#ifndef SKC_MACROS_H
#define SKC_MACROS_H

#include <Base/errors.h>
#include <Base/macros.h>

#ifdef SKC_EXTERN_DEBUG
#	define SKC_ASSERT_MSG(boolean, msg_ptr) Base_assert_msg(boolean, msg_ptr)
#	define SKC_ASSERT(boolean)		Base_assert(boolean)
#else
#	define SKC_ASSERT_MSG(boolean, msg_ptr) /* Nil */
#	define SKC_ASSERT(boolean)		/* Nil */
#endif

#ifdef SKC_EXTERN_STATIC_LIB
#	define SKC_API /* Nil */
#	define SKC_API_IS_NIL
#else
#	ifdef SKC_EXTERN_BUILD_DYNAMIC_LIB
#		define SKC_API BASE_EXPORT
#		define SKC_API_IS_EXPORT
#		ifdef BASE_EXPORT_IS_NIL
#			define SKC_API_IS_NIL
#		endif
#	else /* Assume Skc is being imported as a dynamic lib. */
#		define SKC_API BASE_IMPORT
#		define SKC_API_IS_IMPORT
#		ifdef BASE_IMPORT_IS_NIL
#			define SKC_API_IS_NIL
#		endif
#	endif
#endif

#endif /* ~ SKC_MACROS_H */
