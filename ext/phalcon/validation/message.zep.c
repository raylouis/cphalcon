
#ifdef HAVE_CONFIG_H
#include "../../ext_config.h"
#endif

#include <php.h>
#include "../../php_ext.h"
#include "../../ext.h"

#include <Zend/zend_operators.h>
#include <Zend/zend_exceptions.h>
#include <Zend/zend_interfaces.h>

#include "kernel/main.h"
#include "kernel/object.h"
#include "kernel/memory.h"
#include "ext/spl/spl_exceptions.h"
#include "kernel/exception.h"
#include "kernel/operators.h"
#include "kernel/fcall.h"
#include "kernel/array.h"


/**
 * Phalcon\Validation\Message
 *
 * Encapsulates validation info generated in the validation process
 */
ZEPHIR_INIT_CLASS(Phalcon_Validation_Message) {

	ZEPHIR_REGISTER_CLASS(Phalcon\\Validation, Message, phalcon, validation_message, phalcon_validation_message_method_entry, 0);

	zend_declare_property_null(phalcon_validation_message_ce, SL("_type"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_message_ce, SL("_message"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_message_ce, SL("_field"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_declare_property_null(phalcon_validation_message_ce, SL("_code"), ZEND_ACC_PROTECTED TSRMLS_CC);

	zend_class_implements(phalcon_validation_message_ce TSRMLS_CC, 1, phalcon_validation_messageinterface_ce);
	return SUCCESS;

}

/**
 * Phalcon\Validation\Message constructor
 */
PHP_METHOD(Phalcon_Validation_Message, __construct) {

	int code;
	zval *message_param = NULL, *field = NULL, field_sub, *type_param = NULL, *code_param = NULL, __$null, _0;
	zval message, type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&type);
	ZVAL_UNDEF(&field_sub);
	ZVAL_NULL(&__$null);
	ZVAL_UNDEF(&_0);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 3, &message_param, &field, &type_param, &code_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}
	if (!field) {
		field = &field_sub;
		field = &__$null;
	}
	if (!type_param) {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_STRING(&type, "");
	} else {
		zephir_get_strval(&type, type_param);
	}
	if (!code_param) {
		code = 0;
	} else {
		code = zephir_get_intval(code_param);
	}


	zephir_update_property_zval(this_ptr, SL("_message"), &message);
	zephir_update_property_zval(this_ptr, SL("_field"), field);
	zephir_update_property_zval(this_ptr, SL("_type"), &type);
	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, code);
	zephir_update_property_zval(this_ptr, SL("_code"), &_0);
	ZEPHIR_MM_RESTORE();

}

/**
 * Sets message type
 */
PHP_METHOD(Phalcon_Validation_Message, setType) {

	zval *type_param = NULL;
	zval type;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&type);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &type_param);

	if (unlikely(Z_TYPE_P(type_param) != IS_STRING && Z_TYPE_P(type_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'type' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(type_param) == IS_STRING)) {
		zephir_get_strval(&type, type_param);
	} else {
		ZEPHIR_INIT_VAR(&type);
		ZVAL_EMPTY_STRING(&type);
	}


	zephir_update_property_zval(this_ptr, SL("_type"), &type);
	RETURN_THIS();

}

/**
 * Returns message type
 */
PHP_METHOD(Phalcon_Validation_Message, getType) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_type");

}

/**
 * Sets verbose message
 */
PHP_METHOD(Phalcon_Validation_Message, setMessage) {

	zval *message_param = NULL;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	if (unlikely(Z_TYPE_P(message_param) != IS_STRING && Z_TYPE_P(message_param) != IS_NULL)) {
		zephir_throw_exception_string(spl_ce_InvalidArgumentException, SL("Parameter 'message' must be a string") TSRMLS_CC);
		RETURN_MM_NULL();
	}
	if (likely(Z_TYPE_P(message_param) == IS_STRING)) {
		zephir_get_strval(&message, message_param);
	} else {
		ZEPHIR_INIT_VAR(&message);
		ZVAL_EMPTY_STRING(&message);
	}


	zephir_update_property_zval(this_ptr, SL("_message"), &message);
	RETURN_THIS();

}

/**
 * Returns verbose message
 */
PHP_METHOD(Phalcon_Validation_Message, getMessage) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Sets field name related to message
 */
PHP_METHOD(Phalcon_Validation_Message, setField) {

	zval *field, field_sub;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&field_sub);

	zephir_fetch_params(0, 1, 0, &field);



	zephir_update_property_zval(this_ptr, SL("_field"), field);
	RETURN_THISW();

}

/**
 * Returns field name related to message
 *
 * @return mixed
 */
PHP_METHOD(Phalcon_Validation_Message, getField) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_field");

}

/**
 * Sets code for the message
 */
PHP_METHOD(Phalcon_Validation_Message, setCode) {

	zval *code_param = NULL, _0;
	int code;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&_0);

	zephir_fetch_params(0, 1, 0, &code_param);

	code = zephir_get_intval(code_param);


	ZEPHIR_INIT_ZVAL_NREF(_0);
	ZVAL_LONG(&_0, code);
	zephir_update_property_zval(this_ptr, SL("_code"), &_0);
	RETURN_THISW();

}

/**
 * Returns the message code
 */
PHP_METHOD(Phalcon_Validation_Message, getCode) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_code");

}

/**
 * Magic __toString method returns verbose message
 */
PHP_METHOD(Phalcon_Validation_Message, __toString) {

	ZEPHIR_INIT_THIS();


	RETURN_MEMBER(this_ptr, "_message");

}

/**
 * Magic __set_state helps to recover messages from serialization
 */
PHP_METHOD(Phalcon_Validation_Message, __set_state) {

	int ZEPHIR_LAST_CALL_STATUS;
	zval *message_param = NULL, _0, _1, _2;
	zval message;
	ZEPHIR_INIT_THIS();

	ZVAL_UNDEF(&message);
	ZVAL_UNDEF(&_0);
	ZVAL_UNDEF(&_1);
	ZVAL_UNDEF(&_2);

	ZEPHIR_MM_GROW();
	zephir_fetch_params(1, 1, 0, &message_param);

	ZEPHIR_OBS_COPY_OR_DUP(&message, message_param);


	object_init_ex(return_value, phalcon_validation_message_ce);
	zephir_array_fetch_string(&_0, &message, SL("_message"), PH_NOISY | PH_READONLY, "phalcon/validation/message.zep", 134 TSRMLS_CC);
	zephir_array_fetch_string(&_1, &message, SL("_field"), PH_NOISY | PH_READONLY, "phalcon/validation/message.zep", 134 TSRMLS_CC);
	zephir_array_fetch_string(&_2, &message, SL("_type"), PH_NOISY | PH_READONLY, "phalcon/validation/message.zep", 134 TSRMLS_CC);
	ZEPHIR_CALL_METHOD(NULL, return_value, "__construct", NULL, 464, &_0, &_1, &_2);
	zephir_check_call_status();
	RETURN_MM();

}
