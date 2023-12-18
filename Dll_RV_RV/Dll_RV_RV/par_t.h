/*!
 * @file par.h
 * @brief �������� ��������� (����������� ������������ �����)
 * @author ���� �������
 * @copyright �� ��� "�����������������", ���-1
 * @details
 * #### ����� ����
 *    ���
 * #### �����������
 *    ���
 */
#pragma once
#ifdef __cplusplus
#ifndef LIBIMIT_API
#if defined(_WIN32) && defined(LIBIMIT_EXPORTS)
#define LIBIMIT_API __declspec(dllexport)
#elif defined(_WIN32)
#define LIBIMIT_API __declspec(dllimport)
#elif defined(__GNUC__) && defined(LIBIMIT_EXPORTS)
#define LIBIMIT_API __attribute__((visibility("default")))
#else
#define LIBIMIT_API
#endif
#endif
#ifndef _WIN32
#define __stdcall //!< ���������� � �������
#endif

#include <cstring>
#include <vector>
#include <fstream>
#pragma warning(disable : 26812)

 //! ��������� ��������� ���������
typedef enum par_status_t {
    PAR_STATUS_MANUAL,  //!< ������ ���������� (�������� ��������� �������)
    PAR_STATUS_AUTO,    //!< �������������� ���������� (�� �������� ��������� �������)
    PAR_STATUS_TEST,    //!< ����-�������� (�� �������� ��������� �������)
    PAR_STATUS_DISABLED //!< �� ������� (�� �������� ��������� �������)
} par_status_t;

//! ����������� ��������� "�� �����������"
typedef enum par_invalid_available_t {
    PAR_CAN_BE_INVALID, //!< ��������� "�� �����������" ��������
    PAR_ALWAYS_VALID    //!< ��������� "�� �����������" �� ��������
} par_invalid_available_t;

//! ��� ������������� ��������� ���������
typedef enum par_coord_type_t {
    PAR_LAT, //!< ������
    PAR_LON  //!< �������
} par_coord_type_t;

//! ����� ����������� ��������� ���� � ������� ���������
typedef enum par_date_time_type_t {
    PAR_DAY = 1,             //!< ���������� ����
    PAR_MONTH = 2,           //!< ���������� �����
    PAR_YEAR = 4,            //!< ���������� ���
    PAR_HOUR = 8,            //!< ���������� ���
    PAR_MINUTE = 0x10,       //!< ���������� ������
    PAR_SECOND = 0x20,       //!< ���������� �������
    PAR_DATE = 7,            //!< ���������� ����
    PAR_TIME = 0x38,         //!< ���������� �����
    PAR_DATE_AND_TIME = 0x3f //!< ���������� ���� � �����
} par_date_time_type_t;

//! ��������� ������ ���������� ���������
typedef enum par_list_status_t {
    PAR_LIST_STATUS_UNDEF,   //!< ������ ���������� � �������������� ���������
    PAR_LIST_STATUS_VALID,   //!< ������ ���������� � ��������� ���������
    PAR_LIST_STATUS_INVALID, //!< ������ ���������� � ����������� ���������
    PAR_LIST_STATUS_HIDDEN   //!< ������ ���������� �����
} par_list_status_t;

//! ��� ������ �������� ��������� ���������
typedef enum par_bool_button_type_t {
    PAR_BOOL_BUTTON_LARGE, //!< ������� ������ (������������)
    PAR_BOOL_BUTTON_SMALL  //!< ��������� ������ (������������)
} par_bool_button_type_t;

//! ��������� ������ �������� �������
typedef enum par_quick_access_button_status_t {
    PAR_BUTTON_STATUS_INACTIVE,      //!< ���������� ���������
    PAR_BUTTON_STATUS_ACTIVE_GREEN,  //!< �������� ��������� (������� ����)
    PAR_BUTTON_STATUS_ACTIVE_YELLOW, //!< �������� ��������� (������ ����)
    PAR_BUTTON_STATUS_ACTIVE_RED     //!< �������� ��������� (������� ����)
} par_quick_access_button_status_t;

//! ��� ������ �������� �������
typedef enum par_quick_access_button_type_t {
    PAR_BUTTON_TYPE_CSO,         //!< ����������� ���������� ����� (���)
    PAR_BUTTON_TYPE_SINGLE_LINE, //!< ������������ ������
    PAR_BUTTON_TYPE_TWO_LINES,   //!< ������������ ������
    PAR_BUTTON_TYPE_WITH_FIRE,   //!< ������ � �����-�������������� (������ � "���������")
    PAR_BUTTON_TYPE_FIRE_ONLY    //!< ������������ �����-������������ (������ "��������")
} par_quick_access_button_type_t;

//! �������� ������� ��������� �������� (����� ������)
typedef enum par_change_flags_t {
    PAR_NOT_CHANGED = 0,      //!< ��������� �� ���������
    PAR_CHANGED_FROM_GUI = 1, //!< ��������� ����� GUI-���������� (���������� ����� - ����������� �������������� ���������)
    PAR_VALUE_CHANGED = 2,    //!< �������� ��������
    PAR_VALID_CHANGED = 4     //!< �������� �������������
} par_change_flags_t;

//! ��� ���������� � ������ �������������� ����������
typedef enum par_log_variable_type_t {
    PAR_LOG_VARIABLE_BOOLEAN, //!< ��� ���������� � ������ �������������� - boolean
    PAR_LOG_VARIABLE_HEX_1,   //!< ��� ���������� � ������ �������������� - 16-������ ����� ������������
    PAR_LOG_VARIABLE_HEX_2,   //!< ��� ���������� � ������ �������������� - 16-������ ����� ������������
    PAR_LOG_VARIABLE_HEX_4,   //!< ��� ���������� � ������ �������������� - 16-������ ����� ���������������
    PAR_LOG_VARIABLE_HEX_8,   //!< ��� ���������� � ������ �������������� - 16-������ ����� ��������������
    PAR_LOG_VARIABLE_DOUBLE,  //!< ��� ���������� � ������ �������������� - double
    PAR_LOG_VARIABLE_FLOAT,   //!< ��� ���������� � ������ �������������� - float
    PAR_LOG_VARIABLE_INT,     //!< ��� ���������� � ������ �������������� - int
    PAR_LOG_VARIABLE_UINT,    //!< ��� ���������� � ������ �������������� - uint
    PAR_LOG_VARIABLE_USHORT,  //!< ��� ���������� � ������ �������������� - ushort
    PAR_LOG_VARIABLE_SHORT,   //!< ��� ���������� � ������ �������������� - short
    PAR_LOG_VARIABLE_UCHAR,   //!< ��� ���������� � ������ �������������� - uchar
    PAR_LOG_VARIABLE_TEXT,    //!< ��� ���������� � ������ �������������� - �����
    PAR_LOG_VARIABLE_ENUM_1,  //!< ��� ���������� � ������ �������������� - ������� ������������ ������������
    PAR_LOG_VARIABLE_ENUM_2,  //!< ��� ���������� � ������ �������������� - ������� ������������ ������������
    PAR_LOG_VARIABLE_ENUM_4   //!< ��� ���������� � ������ �������������� - ������� ������������ ���������������
} par_log_variable_type_t;

//! ���������� ������� ��������� ��� ������ � ������������� enum_type ��� � �������
#define ENABLE_FLAGS_FOR_PAR_ENUM(enum_type)                                                                                    \
   inline enum_type operator~(enum_type a) {                                                                                    \
      return static_cast<enum_type>(~static_cast<unsigned int>(a));                                                             \
   }                                                                                                                            \
   inline enum_type operator|(enum_type a, enum_type b) {                                                                       \
      return static_cast<enum_type>(static_cast<unsigned int>(a) | static_cast<unsigned int>(b));                               \
   }                                                                                                                            \
   inline enum_type operator&(enum_type a, enum_type b) {                                                                       \
      return static_cast<enum_type>(static_cast<unsigned int>(a) & static_cast<unsigned int>(b));                               \
   }                                                                                                                            \
   inline enum_type operator^(enum_type a, enum_type b) {                                                                       \
      return static_cast<enum_type>(static_cast<unsigned int>(a) ^ static_cast<unsigned int>(b));                               \
   }                                                                                                                            \
   inline enum_type &operator|=(enum_type &a, enum_type b) {                                                                    \
      return static_cast<enum_type &>(a = static_cast<enum_type>(static_cast<unsigned int>(a) | static_cast<unsigned int>(b))); \
   }                                                                                                                            \
   inline enum_type &operator&=(enum_type &a, enum_type b) {                                                                    \
      return static_cast<enum_type &>(a = static_cast<enum_type>(static_cast<unsigned int>(a) & static_cast<unsigned int>(b))); \
   }                                                                                                                            \
   inline enum_type &operator^=(enum_type &a, enum_type b) {                                                                    \
      return static_cast<enum_type &>(a = static_cast<enum_type>(static_cast<unsigned int>(a) ^ static_cast<unsigned int>(b))); \
   }
ENABLE_FLAGS_FOR_PAR_ENUM(par_date_time_type_t) //!< ���������� ������� ��������� ��� ������ � �������������� ��� � ������� ��� par_date_time_type_t
ENABLE_FLAGS_FOR_PAR_ENUM(par_change_flags_t)   //!< ���������� ������� ��������� ��� ������ � �������������� ��� � ������� ��� par_change_flags_t
#undef ENABLE_FLAGS_FOR_PAR_ENUM

//! ������������ ���������� �������� ��������� ���������� ���������
#define PAR_STRING_MAX_LENGTH 0xff

//! ������������ ���������� �������� ��������� ���������� ���������
#define PAR_TABLE_COLUMNS_MAX_COUNT 16

//! ������ �� ��������� (� ��������)
#define PAR_LATITUDE_DEFAULT 59.8945501777778

//! ������� �� ��������� (� ��������)
#define PAR_LONGITUDE_DEFAULT 30.28250567571

//! �������� ��������� (����������� ������������ �����)
class par_t {
public:
    /*!
     * �������� ��������� (����������� ������������ �����, ����������)
     */
    virtual ~par_t() = default;

    /*!
     * ���������� ������������� ������ ����������
     * @return ������������� ������ ����������
     */
    virtual unsigned char get_list_id() const = 0;                                                     

    /*!
     * ���������� ��������� ������������� ���������
     * @return ��������� ������������� ���������
     */
    virtual const char* get_text_id() const = 0;                                                       

    /*!
     * ���������� ��������
     * @return ��������
     */
    virtual const char* get_name() const = 0;                                                         

    /*!
     * ���������� ������� ������������� �������� ���������
     * @return ������� ������������� �������� ���������
     * @note ���� �������� � ��������� PAR_STATUS_TEST ��� ���� �������� ������ �����������, �� ������������ true
     */
    virtual bool get_valid() const = 0;                                                                 

    /*!
     * ������������� ������� ������������� �������� ���������
     * @param valid ������� ������������� �������� ���������
     */
    virtual void set_valid(const bool valid) = 0;

    /*!
     * ���������� ���������
     * @return ���������
     */
    virtual par_status_t get_status() const = 0;                                                        

    /*!
     * ������������� c��������
     * @param status ���������
     */
    virtual void set_status(const par_status_t status) = 0;

    /*!
     * ���������� ������� ������������� �������� ���������
     * @return ������� ������������� �������� ���������
     */
    virtual bool get_out_of_range() const = 0;                                        

    /*!
     * ������������� ������� ������������� �������� ���������
     * @param out_of_range ������� ������������� �������� ���������
     */
    virtual void set_out_of_range(const bool out_of_range) = 0;

    /*!
     * ������������� ��������, ������� ������������� �������� � ��������� �� ���������
     */
    virtual void reset() = 0;

    /*!
     * ������������� ��������� �� ���������
     */
    virtual void reset_status() = 0;

    /*!
     * ��������� ���������� ������� ��������� ���������
     * @param handler ����������� ���������� ������� ��������� ��������� (������� � ����������� par_change_handler_t)
     */
    virtual void add_change_handler(void (*handler)(par_t*, const par_change_flags_t)) = 0;//?
    

    /*!
     * ������� ���������� ������� ������� ��������� ���������
     * @param handler ��������� ���������� ������� ������� ��������� ��������� (nullptr - ������� ��� �����������)
     */
    virtual void remove_change_handler(void (*handler)(par_t*, const par_change_flags_t) = nullptr) = 0;//?

    /*!
     * �������� ��� ����������� ������� ��������� ���������, ������������� � ������� add_change_handler
     * (�������� ��� ����������� ��������� ���������, ���� ���� �������� �� ��� �������)
     * @param change_flags �������� ������� ��������� �������� (����� ������)
     */
    virtual void invoke_change_handlers(const par_change_flags_t change_flags = static_cast<par_change_flags_t>(PAR_VALUE_CHANGED | PAR_VALID_CHANGED)) = 0;

    /*!
     * ��������� �������� � ��������� ��������� �� ��������� �������, ����������� �� GUI-����������
     * @param[in] array �������� ������
     * @param[in] array_size ������ ��������� �������
     * @note ������������ ��� ������ ������ � ������ ��������� ��������� � ������� GUI-����������
     */
    virtual void from_byte_array(const void* array, const size_t array_size) = 0;

    /*!
     * ���������� �������� � ��������� ��������� � �������� ������, ����������� ��� GUI-����������
     * @param[out] array �������� ������
     * @param[in] array_size ��������� ������ ��������� �������
     * @return ��������������� ��� ������ ������ ��������� �������
     * @note ������������ ��� �������� �������� � ��������� ��������� � GUI-����������
     */
    virtual size_t to_byte_array(void* array, const size_t array_size) const = 0;

    /*!
     * ���������� ����������������� ������ ��������� � �������� ������, ����������� ��� GUI-����������
     * @param[out] array �������� ������
     * @param[in] array_size ��������� ������ ��������� �������
     * @return ��������������� ��� ������ ������ ��������� �������
     * @note ������������ ��� ��������� �������� ���������� � ��������� � GUI-����������
     */
    virtual size_t to_init_array(void* array, const size_t array_size) const = 0;

    /*!
     * ������������� �������� �� ���������� ������� (����� ��� ������ � ����������� �����������)
     * @param text_request ��������� ������
     * @return ����������
     */
    virtual bool set_value_from_text_request(const char* text_request) = 0;                                                

    /*!
     * ��������� �������� � ������ ��������������
     * @param system_name �������� ������� �� ����������� (nullptr - �������� ������)
     * @param par_name �������� ��������� �� ����������� (nullptr - �������������� ������������ ���������)
     */
    virtual void add_to_log_pars(const char* system_name = nullptr, const char* par_name = nullptr) = 0;

    /*!
     * ������� �������� �� ������ ��������������
     */
    virtual void remove_from_log_pars() = 0;

    /*!
     * ���������� ����� ��������� � ������ ���� ����������, ��������� � ���������� (���������� �������������)
     * @return ����� ��������� � ������ ���� ����������, ��������� � ���������� (��������� � ����)
     */
    virtual unsigned int get_index() const = 0;                                                                          

    /*!
     * ���������� ����������� ����� ����������� ����� ���������
     * @return ����������� ����� ����������� ����� ���������
     */
    virtual unsigned int get_checksum() const = 0;

    /*!
     * �������� �������� �� ������� ��������� ���� �� ����
     * @param par ��������-�������� ��������
     * @note ��������� ������ ����� ���� ��� (��������� ��������� - ���������� ������������ ������ ������)
     */
    virtual void set_value_from(const par_t* par) = 0;

    /*!
     * ��������� ������� �������� � ������������� ��������� (��� ����������� ������������ ������������ ��� ������� ������ load)
     */
    virtual void save() = 0;

    /*!
     * ��������������� �������� � ������������� ���������, ����������� ����� ������� ������ save
     */
    virtual void load() = 0;

    /*!
     * ��������� � ������ ���������� (������ ���, ��� ��������� �������� ����� ����� ���������� ������ � ��� ��������� ������ �������� � ��������� �������)
     * @param par ����������� ��������
     * @note ��������� ������ ����� ���� ��� (��������� ��������� - ���������� ������������ ������ ������)
     */
    virtual void link_with(par_t* par) = 0;

    /*!
     * ���������� ����� � ������ ����������
     * @param par ������������ ��������
     */
    virtual void unlink_from(par_t* par) = 0;
};

/*!
 * ���������� ��������� �� �������� � ��������� �������
 * @param index ����� ��������� (��������� � ����)
 * @return ��������� �� �������� (nullptr - ��������� � ��������� ������� �� ����������)
 */
extern "C" LIBIMIT_API par_t * __stdcall get_par(const unsigned int index);

/*!
 * ���������� ���������� ����������, ��������� � ����������
 * @return ���������� ���������� � ������
 */
extern "C" LIBIMIT_API size_t __stdcall get_pars_count();

/*!
 * ���������� ����������� ����� ����������� ����� ����������, ��������� � ����������
 * @return ����������� ����� ����������� ����� ����������, ��������� � ����������
 */
extern "C" LIBIMIT_API unsigned int __stdcall get_pars_checksum();

/*!
 * ���������� ��� ��������� ���������
 */
extern "C" LIBIMIT_API void __stdcall destroy_all_pars();

/*!
 * �������������� ����������� ����������
 * @param filename ��� ����� ����������� ���������� (nullptr - ��������� �����������)
 * @return ����������
 */
extern "C" LIBIMIT_API unsigned int __stdcall par_log_init(const char* filename);

/*!
 * ������� ���� ����������� ����������
 * @return ����������
 */
extern "C" LIBIMIT_API unsigned int __stdcall par_log_clear();

/*!
 * ��������� ����������� ���������� (������� ��� ������������ ������)
 * @param on ��������� ����������� ����������
 */
extern "C" LIBIMIT_API void __stdcall par_log_update(const unsigned int on);

/*!
 * ��������� ���������� � ������ ��������������
 * @param variable_type ��� ����������
 * @param variable_setting �������������� ��������� ���������� (��� PAR_LOG_VARIABLE_TEXT - ����� ������ (�������� const uint *), ��� PAR_LOG_VARIABLE_ENUM_X - ������ �������� ������������ (�������� const char *))
 * @param variable_ptr ��������� �� ����������
 * @param system_name �������� ������� �� ����������� (nullptr - �������� ������)
 * @param variable_name �������� ���������� �� �����������
 */
extern "C" LIBIMIT_API void __stdcall par_log_variable_add(const par_log_variable_type_t variable_type, const void* variable_setting, void* variable_ptr, const char* system_name, const char* variable_name);

/*!
 * ������� ���������� �� ������ ��������������
 * @param variable_ptr ��������� �� ���������� (nullptr - ������� ���)
 */
extern "C" LIBIMIT_API void __stdcall par_log_variable_remove(void* variable_ptr = nullptr);

//! ���������� ������� ��������� �������� ��� ��������� ���������
typedef void(par_change_handler_t)(par_t*, const par_change_flags_t);

#endif
