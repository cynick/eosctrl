
#include "util.h"
#include "err.h"

#include <EDSDK.h>
#include <EDSDKErrors.h>

#include <iostream>

using namespace std;

const char* getPropertyName( EdsUInt32 propId ) {

    const char* ret = NULL;

    switch ( propId ) {

    case kEdsPropID_ProductName:
        ret = "kEdsPropID_ProductName";
        break;

    case kEdsPropID_BodyID:
        ret = "kEdsPropID_BodyID";
        break;

    case kEdsPropID_OwnerName:
        ret = "kEdsPropID_OwnerName";
        break;

    case kEdsPropID_MakerName:
        ret = "kEdsPropID_MakerName";
        break;

    case kEdsPropID_DateTime:
        ret = "kEdsPropID_DateTime";
        break;

    case kEdsPropID_FirmwareVersion:
        ret = "kEdsPropID_FirmwareVersion";
        break;

    case kEdsPropID_BatteryLevel:
        ret = "kEdsPropID_BatteryLevel";
        break;

    case kEdsPropID_CFn:
        ret = "kEdsPropID_CFn";
        break;

    case kEdsPropID_SaveTo:
        ret = "kEdsPropID_SaveTo";
        break;

    case kEdsPropID_CurrentStorage:
        ret = "kEdsPropID_CurrentStorage";
        break;

    case kEdsPropID_CurrentFolder:
        ret = "kEdsPropID_CurrentFolder";
        break;

    case kEdsPropID_MyMenu:
        ret = "kEdsPropID_MyMenu";
        break;

    case kEdsPropID_BatteryQuality:
        ret = "kEdsPropID_BatteryQuality";
        break;

    case kEdsPropID_HDDirectoryStructure:
        ret = "kEdsPropID_HDDirectoryStructure";
        break;

    default:
        ret = "UNKNOWN property";
        break;

    }

    return ret;
}


const char* getDataTypeName( EdsDataType dataType ) {

    const char* ret = NULL;

    switch ( dataType ) {

    case kEdsDataType_Unknown:
        ret = "kEdsDataType_Unknown";
        break;

    case kEdsDataType_Bool:
        ret = "kEdsDataType_Bool";
        break;

    case kEdsDataType_String:
        ret = "kEdsDataType_String";
        break;

    case kEdsDataType_Int8:
        ret = "kEdsDataType_Int8";
        break;

    case kEdsDataType_UInt8:
        ret = "kEdsDataType_UInt8";
        break;

    case kEdsDataType_Int16:
        ret = "kEdsDataType_Int16";
        break;

    case kEdsDataType_UInt16:
        ret = "kEdsDataType_UInt16";
        break;

    case kEdsDataType_Int32:
        ret = "kEdsDataType_Int32";
        break;

    case kEdsDataType_UInt32:
        ret = "kEdsDataType_UInt32";
        break;

    case kEdsDataType_Int64:
        ret = "kEdsDataType_Int64";
        break;

    case kEdsDataType_UInt64:
        ret = "kEdsDataType_UInt64";
        break;

    case kEdsDataType_Float:
        ret = "kEdsDataType_Float";
        break;

    case kEdsDataType_Double:
        ret = "kEdsDataType_Double";
        break;

    case kEdsDataType_ByteBlock:
        ret = "kEdsDataType_ByteBlock";
        break;

    case kEdsDataType_Rational:
        ret = "kEdsDataType_Rational";
        break;

    case kEdsDataType_Point:
        ret = "kEdsDataType_Point";
        break;

    case kEdsDataType_Rect:
        ret = "kEdsDataType_Rect";
        break;

    case kEdsDataType_Time:
        ret = "kEdsDataType_Time";
        break;

    case kEdsDataType_Bool_Array:
        ret = "kEdsDataType_Bool_Array";
        break;

    case kEdsDataType_Int8_Array:
        ret = "kEdsDataType_Int8_Array";
        break;

    case kEdsDataType_Int16_Array:
        ret = "kEdsDataType_Int16_Array";
        break;

    case kEdsDataType_Int32_Array:
        ret = "kEdsDataType_Int32_Array";
        break;

    case kEdsDataType_UInt8_Array:
        ret = "kEdsDataType_UInt8_Array";
        break;

    case kEdsDataType_UInt16_Array:
        ret = "kEdsDataType_UInt16_Array";
        break;

    case kEdsDataType_UInt32_Array:
        ret = "kEdsDataType_UInt32_Array";
        break;

    case kEdsDataType_Rational_Array:
        ret = "kEdsDataType_Rational_Array";
        break;

    case kEdsDataType_FocusInfo:
        ret = "kEdsDataType_FocusInfo";
        break;

    case kEdsDataType_PictureStyleDesc:
        ret = "kEdsDataType_PictureStyleDesc";
        break;

    default:
        ret = "UNKNOWN data type";
        break;
    }

    return ret;

}

const char* getPropertyEventName( EdsPropertyEvent event ) {

    const char* ret = NULL;

    switch ( event ) {

    case kEdsPropertyEvent_All:
        ret = "kEdsPropertyEvent_All";
        break;

    case kEdsPropertyEvent_PropertyChanged:
        ret = "kEdsPropertyEvent_PropertyChanged";
        break;

    case kEdsPropertyEvent_PropertyDescChanged:
        ret = "kEdsPropertyEvent_PropertyDescChanged";
        break;

    default:
        ret = NULL;
        break;
    }
}

const char* getObjectEventName( EdsObjectEvent event ) {

    const char* ret = NULL;

    switch ( event ) {

    case kEdsObjectEvent_All:
        ret = "kEdsObjectEvent_All";
        break;

    case kEdsObjectEvent_VolumeInfoChanged:
        ret = "kEdsObjectEvent_VolumeInfoChanged";
        break;

    case kEdsObjectEvent_VolumeUpdateItems:
        ret = "kEdsObjectEvent_VolumeUpdateItems";
        break;

    case kEdsObjectEvent_FolderUpdateItems:
        ret = "kEdsObjectEvent_FolderUpdateItems";
        break;

    case kEdsObjectEvent_DirItemCreated:
        ret = "kEdsObjectEvent_DirItemCreated";
        break;

    case kEdsObjectEvent_DirItemRemoved:
        ret = "kEdsObjectEvent_DirItemRemoved";
        break;

    case kEdsObjectEvent_DirItemInfoChanged:
        ret = "kEdsObjectEvent_DirItemInfoChanged";
        break;

    case kEdsObjectEvent_DirItemContentChanged:
        ret = "kEdsObjectEvent_DirItemContentChanged";
        break;

    case kEdsObjectEvent_DirItemRequestTransfer:
        ret = "kEdsObjectEvent_DirItemRequestTransfer";
        break;

    case kEdsObjectEvent_DirItemRequestTransferDT:
        ret = "kEdsObjectEvent_DirItemRequestTransferDT";
        break;

    case kEdsObjectEvent_DirItemCancelTransferDT:
        ret = "kEdsObjectEvent_DirItemCancelTransferDT";
        break;

    case kEdsObjectEvent_VolumeAdded:
        ret = "kEdsObjectEvent_VolumeAdded";
        break;

    case kEdsObjectEvent_VolumeRemoved:
        ret = "kEdsObjectEvent_VolumeRemoved";
        break;

    default:
        ret = "UNKNOWN object event";
        break;

    }

    return ret;

}

const char* getStateEventName( EdsStateEvent event ) {

    const char* ret = NULL;

    switch ( event ) {

    case kEdsStateEvent_Shutdown:
        ret = "kEdsStateEvent_Shutdown";
        break;

    case kEdsStateEvent_JobStatusChanged:
        ret = "kEdsStateEvent_JobStatusChanged";
        break;

    case kEdsStateEvent_WillSoonShutDown:
        ret = "kEdsStateEvent_WillSoonShutDown";
        break;

    case kEdsStateEvent_ShutDownTimerUpdate:
        ret = "kEdsStateEvent_ShutDownTimerUpdate";
        break;

    case kEdsStateEvent_CaptureError:
        ret = "kEdsStateEvent_CaptureError";
        break;

    case kEdsStateEvent_InternalError:
        ret = "kEdsStateEvent_InternalError";
        break;

    case kEdsStateEvent_AfResult:
        ret = "kEdsStateEvent_AfResult";
        break;

    case kEdsStateEvent_BulbExposureTime:
        ret = "kEdsStateEvent_BulbExposureTime";
        break;

    default:
        ret = "UNKNOWN state event";
        break;
    }

    return ret;
}


void dumpProperties( EdsBaseRef camera ) {

    const EdsPropertyID props[] = {
        kEdsPropID_Unknown,
        kEdsPropID_ProductName,
        kEdsPropID_BodyID,
        kEdsPropID_OwnerName,
        kEdsPropID_MakerName,
        kEdsPropID_DateTime,
        kEdsPropID_FirmwareVersion,
        kEdsPropID_BatteryLevel,
        kEdsPropID_CFn,
        kEdsPropID_SaveTo,
        kEdsPropID_CurrentStorage,
        kEdsPropID_CurrentFolder,
        kEdsPropID_MyMenu,
        kEdsPropID_BatteryQuality,
        kEdsPropID_HDDirectoryStructure,
    };

    for ( int index = 0;
          index < (sizeof(props) / sizeof( EdsPropertyID ));
          index++ ) {

        EdsPropertyID prop = props[ index ];

        EdsError err = EDS_ERR_OK;

        EdsDataType dataType;
        EdsUInt32 dataSize;

        if ( (err = EdsGetPropertySize( camera, prop, 0,
                                        &dataType, &dataSize ) ) ) {
            cout << "Failed to get property " << getPropertyName( prop )
                 << ": " << getErrorString( err ) << endl;
            continue;
        }

        cout <<
            "Property " << getPropertyName( prop ) <<
            " has type=" << getDataTypeName( dataType ) <<
            ",size=" << dataSize << endl;

        switch ( dataType ) {

        case kEdsDataType_Bool:
            {
                EdsBool data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }

                cout << "Property " <<
                    getPropertyName( prop ) <<
                    "has value " << data;
            }
            break;

        case kEdsDataType_String:
            {
                EdsChar data[ dataSize ];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }

                cout << "Property " <<
                    getPropertyName( prop ) <<
                    "has value " << string(data);
            }
            break;

        case kEdsDataType_Int8:
            {
                EdsInt8 data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_UInt8:
            {
                EdsUInt8 data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Int16:
            {
                EdsInt16 data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_UInt16:
            {
                EdsUInt16 data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Int32:
            {
                EdsInt32 data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_UInt32:
            {
                EdsUInt32 data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Int64:
            {
                EdsInt64 data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_UInt64:
            {
                EdsUInt64 data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Float:
            {
                EdsFloat data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Double:
            {
                EdsDouble data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_ByteBlock:
            {
                EdsInt8 data[dataSize];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Rational:
            {
                EdsRational data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Point:
            {
                EdsPoint data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Rect:
            {
                EdsRect data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Time:
            {
                EdsTime data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Int8_Array:
            {
                EdsInt8 data[dataSize];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Int16_Array:
            {
                EdsInt16 data[dataSize];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Int32_Array:
            {
                EdsInt32 data[dataSize];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_UInt8_Array:
            {
                EdsUInt8 data[dataSize];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_UInt16_Array:
            {
                EdsUInt16 data[dataSize];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_UInt32_Array:
            {
                EdsUInt32 data[dataSize];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_Rational_Array:
            {
                EdsRational data[dataSize];

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;


        case kEdsDataType_FocusInfo:
            {
                EdsFocusInfo data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        case kEdsDataType_PictureStyleDesc:
            {
                EdsPictureStyleDesc data;

                if ( (err = EdsGetPropertyData( camera, prop, 0,
                                                dataSize, &data )) !=
                     EDS_ERR_OK ) {

                    cout << "Failed to get property " <<
                        getPropertyName( prop )
                         << ": " <<
                        getErrorString(err) << endl;
                }
            }
            break;

        default:

            cout << "UNKNOWN data type: " << dataType << endl;
            break;
        }

    }

}

