
#include "err.h"

const char* getErrorString( EdsError error ) { 
    
    const char* ret;
    
    switch ( error ) {

    case EDS_ERR_UNIMPLEMENTED:
        ret = "EDS_ERR_UNIMPLEMENTED";
        break;

    case EDS_ERR_INTERNAL_ERROR:
        ret = "EDS_ERR_INTERNAL_ERROR";
        break;
        
    case EDS_ERR_MEM_ALLOC_FAILED:
        ret = "EDS_ERR_MEM_ALLOC_FAILED";
        break;

    case EDS_ERR_MEM_FREE_FAILED:
        ret = "EDS_ERR_MEM_FREE_FAILED";
        break;

    case EDS_ERR_OPERATION_CANCELLED:
        ret = "EDS_ERR_OPERATION_CANCELLED";
        break;

    case EDS_ERR_INCOMPATIBLE_VERSION:
        ret = "EDS_ERR_INCOMPATIBLE_VERSION";
        break;

    case EDS_ERR_NOT_SUPPORTED:
        ret = "EDS_ERR_NOT_SUPPORTED";
        break;

    case EDS_ERR_UNEXPECTED_EXCEPTION:
        ret = "EDS_ERR_UNEXPECTED_EXCEPTION";
        break;

    case EDS_ERR_PROTECTION_VIOLATION:
        ret = "EDS_ERR_PROTECTION_VIOLATION";
        break;

    case EDS_ERR_MISSING_SUBCOMPONENT:
        ret = "EDS_ERR_MISSING_SUBCOMPONENT";
        break;

    case EDS_ERR_SELECTION_UNAVAILABLE:
        ret = "EDS_ERR_SELECTION_UNAVAILABLE";
        break;

    case EDS_ERR_FILE_IO_ERROR:
        ret = "EDS_ERR_FILE_IO_ERROR";
        break;

    case EDS_ERR_FILE_TOO_MANY_OPEN:
        ret = "EDS_ERR_FILE_TOO_MANY_OPEN";
        break;

    case EDS_ERR_FILE_NOT_FOUND:
        ret = "EDS_ERR_FILE_NOT_FOUND";
        break;

    case EDS_ERR_FILE_OPEN_ERROR:
        ret = "EDS_ERR_FILE_OPEN_ERROR";
        break;

    case EDS_ERR_FILE_CLOSE_ERROR:
        ret = "EDS_ERR_FILE_CLOSE_ERROR";
        break;

    case EDS_ERR_FILE_SEEK_ERROR:
        ret = "EDS_ERR_FILE_SEEK_ERROR";
        break;

    case EDS_ERR_FILE_TELL_ERROR:
        ret = "EDS_ERR_FILE_TELL_ERROR";
        break;

    case EDS_ERR_FILE_READ_ERROR:
        ret = "EDS_ERR_FILE_READ_ERROR";
        break;

    case EDS_ERR_FILE_WRITE_ERROR:
        ret = "EDS_ERR_FILE_WRITE_ERROR";
        break;

    case EDS_ERR_FILE_PERMISSION_ERROR:
        ret = "EDS_ERR_FILE_PERMISSION_ERROR";
        break;

    case EDS_ERR_FILE_DISK_FULL_ERROR:
        ret = "EDS_ERR_FILE_DISK_FULL_ERROR";
        break;

    case EDS_ERR_FILE_ALREADY_EXISTS:
        ret = "EDS_ERR_FILE_ALREADY_EXISTS";
        break;
        
    case EDS_ERR_FILE_FORMAT_UNRECOGNIZED:
        ret = "EDS_ERR_FILE_FORMAT_UNRECOGNIZED";
        break;

    case EDS_ERR_FILE_DATA_CORRUPT:
        ret = "EDS_ERR_FILE_DATA_CORRUPT";
        break;

    case EDS_ERR_FILE_NAMING_NA:
        ret = "EDS_ERR_FILE_NAMING_NA";
        break;

    case EDS_ERR_DIR_NOT_FOUND:
        ret = "EDS_ERR_DIR_NOT_FOUND";
        break;

    case EDS_ERR_DIR_IO_ERROR:
        ret = "EDS_ERR_DIR_IO_ERROR";
        break;

    case EDS_ERR_DIR_ENTRY_NOT_FOUND:
        ret = "EDS_ERR_DIR_ENTRY_NOT_FOUND";
        break;

    case EDS_ERR_DIR_ENTRY_EXISTS:
        ret = "EDS_ERR_DIR_ENTRY_EXISTS";
        break;

    case EDS_ERR_DIR_NOT_EMPTY:
        ret = "EDS_ERR_DIR_NOT_EMPTY";
        break;

    case EDS_ERR_PROPERTIES_UNAVAILABLE:
        ret = "EDS_ERR_PROPERTIES_UNAVAILABLE";
        break;

    case EDS_ERR_PROPERTIES_MISMATCH:
        ret = "EDS_ERR_PROPERTIES_MISMATCH";
        break;

    case EDS_ERR_PROPERTIES_NOT_LOADED:
        ret = "EDS_ERR_PROPERTIES_NOT_LOADED";
        break;

    case EDS_ERR_INVALID_PARAMETER:
        ret = "EDS_ERR_INVALID_PARAMETER";
        break;

    case EDS_ERR_INVALID_HANDLE:
        ret = "EDS_ERR_INVALID_HANDLE";
        break;

    case EDS_ERR_INVALID_POINTER:
        ret = "EDS_ERR_INVALID_POINTER";
        break;

    case EDS_ERR_INVALID_INDEX:
        ret = "EDS_ERR_INVALID_INDEX";
        break;

    case EDS_ERR_INVALID_LENGTH:
        ret = "EDS_ERR_INVALID_LENGTH";
        break;

    case EDS_ERR_INVALID_FN_POINTER:
        ret = "EDS_ERR_INVALID_FN_POINTER";
        break;

    case EDS_ERR_INVALID_SORT_FN:
        ret = "EDS_ERR_INVALID_SORT_FN";
        break;

    case EDS_ERR_DEVICE_NOT_FOUND:
        ret = "EDS_ERR_DEVICE_NOT_FOUND";
        break;

    case EDS_ERR_DEVICE_BUSY:
        ret = "EDS_ERR_DEVICE_BUSY";
        break;

    case EDS_ERR_DEVICE_INVALID:
        ret = "EDS_ERR_DEVICE_INVALID";
        break;

    case EDS_ERR_DEVICE_EMERGENCY:
        ret = "EDS_ERR_DEVICE_EMERGENCY";
        break;

    case EDS_ERR_DEVICE_MEMORY_FULL:
        ret = "EDS_ERR_DEVICE_MEMORY_FULL";
        break;

    case EDS_ERR_DEVICE_INTERNAL_ERROR:
        ret = "EDS_ERR_DEVICE_INTERNAL_ERROR";
        break;

    case EDS_ERR_DEVICE_INVALID_PARAMETER:
        ret = "EDS_ERR_DEVICE_INVALID_PARAMETER";
        break;

    case EDS_ERR_DEVICE_NO_DISK:
        ret = "EDS_ERR_DEVICE_NO_DISK";
        break;

    case EDS_ERR_DEVICE_DISK_ERROR:
        ret = "EDS_ERR_DEVICE_DISK_ERROR";
        break;

    case EDS_ERR_DEVICE_CF_GATE_CHANGED:
        ret = "EDS_ERR_DEVICE_CF_GATE_CHANGED";
        break;

    case EDS_ERR_DEVICE_DIAL_CHANGED:
        ret = "EDS_ERR_DEVICE_DIAL_CHANGED";
        break;

    case EDS_ERR_DEVICE_NOT_INSTALLED:
        ret = "EDS_ERR_DEVICE_NOT_INSTALLED";
        break;

    case EDS_ERR_DEVICE_STAY_AWAKE:
        ret = "EDS_ERR_DEVICE_STAY_AWAKE";
        break;

    case EDS_ERR_DEVICE_NOT_RELEASED:
        ret = "EDS_ERR_DEVICE_NOT_RELEASED";
        break;

    case EDS_ERR_STREAM_IO_ERROR:
        ret = "EDS_ERR_STREAM_IO_ERROR";
        break;

    case EDS_ERR_STREAM_NOT_OPEN:
        ret = "EDS_ERR_STREAM_NOT_OPEN";
        break;

    case EDS_ERR_STREAM_ALREADY_OPEN:
        ret = "EDS_ERR_STREAM_ALREADY_OPEN";
        break;

    case EDS_ERR_STREAM_OPEN_ERROR:
        ret = "EDS_ERR_STREAM_OPEN_ERROR";
        break;

    case EDS_ERR_STREAM_CLOSE_ERROR:
        ret = "EDS_ERR_STREAM_CLOSE_ERROR";
        break;

    case EDS_ERR_STREAM_SEEK_ERROR:
        ret = "EDS_ERR_STREAM_SEEK_ERROR";
        break;

    case EDS_ERR_STREAM_TELL_ERROR:
        ret = "EDS_ERR_STREAM_TELL_ERROR";
        break;

    case EDS_ERR_STREAM_READ_ERROR:
        ret = "EDS_ERR_STREAM_READ_ERROR";
        break;

    case EDS_ERR_STREAM_WRITE_ERROR:
        ret = "EDS_ERR_STREAM_WRITE_ERROR";
        break;

    case EDS_ERR_STREAM_PERMISSION_ERROR:
        ret = "EDS_ERR_STREAM_PERMISSION_ERROR";
        break;

    case EDS_ERR_STREAM_COULDNT_BEGIN_THREAD:
        ret = "EDS_ERR_STREAM_COULDNT_BEGIN_THREAD";
        break;

    case EDS_ERR_STREAM_BAD_OPTIONS:
        ret = "EDS_ERR_STREAM_BAD_OPTIONS";
        break;

    case EDS_ERR_STREAM_END_OF_STREAM:
        ret = "EDS_ERR_STREAM_END_OF_STREAM";
        break;

    case EDS_ERR_COMM_PORT_IS_IN_USE:
        ret = "EDS_ERR_COMM_PORT_IS_IN_USE";
        break;

    case EDS_ERR_COMM_DISCONNECTED:
        ret = "EDS_ERR_COMM_DISCONNECTED";
        break;

    case EDS_ERR_COMM_DEVICE_INCOMPATIBLE:
        ret = "EDS_ERR_COMM_DEVICE_INCOMPATIBLE";
        break;

    case EDS_ERR_COMM_BUFFER_FULL:
        ret = "EDS_ERR_COMM_BUFFER_FULL";
        break;

    case EDS_ERR_COMM_USB_BUS_ERR:
        ret = "EDS_ERR_COMM_USB_BUS_ERR";
        break;

    case EDS_ERR_USB_DEVICE_LOCK_ERROR:
        ret = "EDS_ERR_USB_DEVICE_LOCK_ERROR";
        break;

    case EDS_ERR_USB_DEVICE_UNLOCK_ERROR:
        ret = "EDS_ERR_USB_DEVICE_UNLOCK_ERROR";
        break;

    case EDS_ERR_STI_UNKNOWN_ERROR:
        ret = "EDS_ERR_STI_UNKNOWN_ERROR";
        break;

    case EDS_ERR_STI_INTERNAL_ERROR:
        ret = "EDS_ERR_STI_INTERNAL_ERROR";
        break;

    case EDS_ERR_STI_DEVICE_CREATE_ERROR:
        ret = "EDS_ERR_STI_DEVICE_CREATE_ERROR";
        break;

    case EDS_ERR_STI_DEVICE_RELEASE_ERROR:
        ret = "EDS_ERR_STI_DEVICE_RELEASE_ERROR";
        break;

    case EDS_ERR_DEVICE_NOT_LAUNCHED:
        ret = "EDS_ERR_DEVICE_NOT_LAUNCHED";
        break;

    case EDS_ERR_ENUM_NA:
        ret = "EDS_ERR_ENUM_NA";
        break;

    case EDS_ERR_INVALID_FN_CALL:
        ret = "EDS_ERR_INVALID_FN_CALL";
        break;

    case EDS_ERR_HANDLE_NOT_FOUND:
        ret = "EDS_ERR_HANDLE_NOT_FOUND";
        break;

    case EDS_ERR_INVALID_ID:
        ret = "EDS_ERR_INVALID_ID";
        break;

    case EDS_ERR_WAIT_TIMEOUT_ERROR:
        ret = "EDS_ERR_WAIT_TIMEOUT_ERROR";
        break;

    case EDS_ERR_SESSION_NOT_OPEN:
        ret = "EDS_ERR_SESSION_NOT_OPEN";
        break;

    case EDS_ERR_INVALID_TRANSACTIONID:
        ret = "EDS_ERR_INVALID_TRANSACTIONID";
        break;

    case EDS_ERR_INCOMPLETE_TRANSFER:
        ret = "EDS_ERR_INCOMPLETE_TRANSFER";
        break;

    case EDS_ERR_INVALID_STRAGEID:
        ret = "EDS_ERR_INVALID_STRAGEID";
        break;

    case EDS_ERR_DEVICEPROP_NOT_SUPPORTED:
        ret = "EDS_ERR_DEVICEPROP_NOT_SUPPORTED";
        break;

    case EDS_ERR_INVALID_OBJECTFORMATCODE:
        ret = "EDS_ERR_INVALID_OBJECTFORMATCODE";
        break;

    case EDS_ERR_SELF_TEST_FAILED:
        ret = "EDS_ERR_SELF_TEST_FAILED";
        break;

    case EDS_ERR_PARTIAL_DELETION:
        ret = "EDS_ERR_PARTIAL_DELETION";
        break;

    case EDS_ERR_SPECIFICATION_BY_FORMAT_UNSUPPORTED:
        ret = "EDS_ERR_SPECIFICATION_BY_FORMAT_UNSUPPORTED";
        break;

    case EDS_ERR_NO_VALID_OBJECTINFO:
        ret = "EDS_ERR_NO_VALID_OBJECTINFO";
        break;

    case EDS_ERR_INVALID_CODE_FORMAT:
        ret = "EDS_ERR_INVALID_CODE_FORMAT";
        break;

    case EDS_ERR_UNKNOWN_VENDOR_CODE:
        ret = "EDS_ERR_UNKNOWN_VENDOR_CODE";
        break;

    case EDS_ERR_CAPTURE_ALREADY_TERMINATED:
        ret = "EDS_ERR_CAPTURE_ALREADY_TERMINATED";
        break;

    case EDS_ERR_INVALID_PARENTOBJECT:
        ret = "EDS_ERR_INVALID_PARENTOBJECT";
        break;

    case EDS_ERR_INVALID_DEVICEPROP_FORMAT:
        ret = "EDS_ERR_INVALID_DEVICEPROP_FORMAT";
        break;

    case EDS_ERR_INVALID_DEVICEPROP_VALUE:
        ret = "EDS_ERR_INVALID_DEVICEPROP_VALUE";
        break;

    case EDS_ERR_SESSION_ALREADY_OPEN:
        ret = "EDS_ERR_SESSION_ALREADY_OPEN";
        break;

    case EDS_ERR_TRANSACTION_CANCELLED:
        ret = "EDS_ERR_TRANSACTION_CANCELLED";
        break;

    case EDS_ERR_SPECIFICATION_OF_DESTINATION_UNSUPPORTED:
        ret = "EDS_ERR_SPECIFICATION_OF_DESTINATION_UNSUPPORTED";
        break;

    case EDS_ERR_UNKNOWN_COMMAND:
        ret = "EDS_ERR_UNKNOWN_COMMAND";
        break;

    case EDS_ERR_OPERATION_REFUSED:
        ret = "EDS_ERR_OPERATION_REFUSED";
        break;

    case EDS_ERR_LENS_COVER_CLOSE:
        ret = "EDS_ERR_LENS_COVER_CLOSE";
        break;

    case EDS_ERR_LOW_BATTERY:
        ret = "EDS_ERR_LOW_BATTERY";
        break;
        
    case EDS_ERR_OBJECT_NOTREADY:
        ret = "EDS_ERR_OBJECT_NOTREADY";
        break;
    
    case EDS_ERR_TAKE_PICTURE_RESERVED:
        ret = "EDS_ERR_TAKE_PICTURE_RESERVED";
        break;
        
    case EDS_ERR_TAKE_PICTURE_MIRROR_UP_NG:
        ret = "EDS_ERR_TAKE_PICTURE_MIRROR_UP_NG";
        break;

    case EDS_ERR_TAKE_PICTURE_SENSOR_CLEANING_NG:
        ret = "EDS_ERR_TAKE_PICTURE_SENSOR_CLEANING_NG";
        break;

    case EDS_ERR_TAKE_PICTURE_SILENCE_NG:
        ret = "EDS_ERR_TAKE_PICTURE_SILENCE_NG";
        break;

    case EDS_ERR_TAKE_PICTURE_NO_CARD_NG:
        ret = "EDS_ERR_TAKE_PICTURE_NO_CARD_NG";
        break;

    case EDS_ERR_TAKE_PICTURE_CARD_NG:
        ret = "EDS_ERR_TAKE_PICTURE_CARD_NG";
        break;

    case EDS_ERR_TAKE_PICTURE_CARD_PROTECT_NG:
        ret = "EDS_ERR_TAKE_PICTURE_CARD_PROTECT_NG";
        break;

    case EDS_ERR_TAKE_PICTURE_MOVIE_CROP_NG	:
        ret = "EDS_ERR_TAKE_PICTURE_MOVIE_CROP_NG	";
        break;

    case EDS_ERR_TAKE_PICTURE_STROBO_CHARGE_NG:
        ret = "EDS_ERR_TAKE_PICTURE_STROBO_CHARGE_NG";
        break;
        
    case EDS_ERR_LAST_GENERIC_ERROR_PLUS_ONE:
        ret = "EDS_ERR_LAST_GENERIC_ERROR_PLUS_ONE";
        break;

    default:
        ret = "UKNOWN error";
    }

    return ret;
}
