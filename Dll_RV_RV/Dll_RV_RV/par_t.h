/*!
 * @file par.h
 * @brief Параметр имитатора (абстрактный родительский класс)
 * @author Илья Кулаков
 * @copyright АО ОКБ "Электроавтоматика", НИЦ-1
 * @details
 * #### Номер ВИДК
 *    нет
 * #### Комментарии
 *    нет
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
#define __stdcall //!< Соглашение о вызовах
#endif

#include <cstring>
#include <vector>
#include <fstream>
#pragma warning(disable : 26812)

 //! Состояние параметра имитатора
typedef enum par_status_t {
    PAR_STATUS_MANUAL,  //!< Ручное управление (доступно изменение вручную)
    PAR_STATUS_AUTO,    //!< Автоматическое управление (не доступно изменение вручную)
    PAR_STATUS_TEST,    //!< Тест-контроль (не доступно изменение вручную)
    PAR_STATUS_DISABLED //!< Не активен (не доступно изменение вручную)
} par_status_t;

//! Доступность состояния "не достоверный"
typedef enum par_invalid_available_t {
    PAR_CAN_BE_INVALID, //!< Состояние "не достоверный" доступно
    PAR_ALWAYS_VALID    //!< Состояние "не достоверный" не доступно
} par_invalid_available_t;

//! Тип координатного параметра имитатора
typedef enum par_coord_type_t {
    PAR_LAT, //!< Широта
    PAR_LON  //!< Долгота
} par_coord_type_t;

//! Режим отображения параметра даты и времени имитатора
typedef enum par_date_time_type_t {
    PAR_DAY = 1,             //!< Отображать день
    PAR_MONTH = 2,           //!< Отображать месяц
    PAR_YEAR = 4,            //!< Отображать год
    PAR_HOUR = 8,            //!< Отображать час
    PAR_MINUTE = 0x10,       //!< Отображать минуту
    PAR_SECOND = 0x20,       //!< Отображать секунду
    PAR_DATE = 7,            //!< Отображать дату
    PAR_TIME = 0x38,         //!< Отображать время
    PAR_DATE_AND_TIME = 0x3f //!< Отображать дату и время
} par_date_time_type_t;

//! Состояние списка параметров имитатора
typedef enum par_list_status_t {
    PAR_LIST_STATUS_UNDEF,   //!< Список параметров в неопределенном состоянии
    PAR_LIST_STATUS_VALID,   //!< Список параметров в исправном состоянии
    PAR_LIST_STATUS_INVALID, //!< Список параметров в неисправном состоянии
    PAR_LIST_STATUS_HIDDEN   //!< Список параметров скрыт
} par_list_status_t;

//! Тип кнопки булевого параметра имитатора
typedef enum par_bool_button_type_t {
    PAR_BOOL_BUTTON_LARGE, //!< Большая кнопка (двухстрочная)
    PAR_BOOL_BUTTON_SMALL  //!< Маленькая кнопка (однострочная)
} par_bool_button_type_t;

//! Состояние кнопки быстрого доступа
typedef enum par_quick_access_button_status_t {
    PAR_BUTTON_STATUS_INACTIVE,      //!< Неактивное состояние
    PAR_BUTTON_STATUS_ACTIVE_GREEN,  //!< Активное состояние (зеленый цвет)
    PAR_BUTTON_STATUS_ACTIVE_YELLOW, //!< Активное состояние (желтый цвет)
    PAR_BUTTON_STATUS_ACTIVE_RED     //!< Активное состояние (красный цвет)
} par_quick_access_button_status_t;

//! Тип кнопки быстрого доступа
typedef enum par_quick_access_button_type_t {
    PAR_BUTTON_TYPE_CSO,         //!< Центральный сигнальный огонь (ЦСО)
    PAR_BUTTON_TYPE_SINGLE_LINE, //!< Однострочная кнопка
    PAR_BUTTON_TYPE_TWO_LINES,   //!< Двухстрочная кнопка
    PAR_BUTTON_TYPE_WITH_FIRE,   //!< Кнопка с огнем-сигнализатором (кнопка с "лампочкой")
    PAR_BUTTON_TYPE_FIRE_ONLY    //!< Ненажимаемый огонь-сигнализатор (только "лампочка")
} par_quick_access_button_type_t;

//! Признаки события изменения праметра (набор флагов)
typedef enum par_change_flags_t {
    PAR_NOT_CHANGED = 0,      //!< Изменения не произошло
    PAR_CHANGED_FROM_GUI = 1, //!< Изменение через GUI-приложения (остутствие флага - программное автоматическое изменение)
    PAR_VALUE_CHANGED = 2,    //!< Изменено значение
    PAR_VALID_CHANGED = 4     //!< Изменена достоверность
} par_change_flags_t;

//! Тип переменной в списке регистрируемых переменных
typedef enum par_log_variable_type_t {
    PAR_LOG_VARIABLE_BOOLEAN, //!< Тип переменной в списке регистрируемых - boolean
    PAR_LOG_VARIABLE_HEX_1,   //!< Тип переменной в списке регистрируемых - 16-ричное число однобайтовое
    PAR_LOG_VARIABLE_HEX_2,   //!< Тип переменной в списке регистрируемых - 16-ричное число двухбайтовое
    PAR_LOG_VARIABLE_HEX_4,   //!< Тип переменной в списке регистрируемых - 16-ричное число четырехбайтовое
    PAR_LOG_VARIABLE_HEX_8,   //!< Тип переменной в списке регистрируемых - 16-ричное число восьмибайтовое
    PAR_LOG_VARIABLE_DOUBLE,  //!< Тип переменной в списке регистрируемых - double
    PAR_LOG_VARIABLE_FLOAT,   //!< Тип переменной в списке регистрируемых - float
    PAR_LOG_VARIABLE_INT,     //!< Тип переменной в списке регистрируемых - int
    PAR_LOG_VARIABLE_UINT,    //!< Тип переменной в списке регистрируемых - uint
    PAR_LOG_VARIABLE_USHORT,  //!< Тип переменной в списке регистрируемых - ushort
    PAR_LOG_VARIABLE_SHORT,   //!< Тип переменной в списке регистрируемых - short
    PAR_LOG_VARIABLE_UCHAR,   //!< Тип переменной в списке регистрируемых - uchar
    PAR_LOG_VARIABLE_TEXT,    //!< Тип переменной в списке регистрируемых - текст
    PAR_LOG_VARIABLE_ENUM_1,  //!< Тип переменной в списке регистрируемых - элемент перечисления однобайтовый
    PAR_LOG_VARIABLE_ENUM_2,  //!< Тип переменной в списке регистрируемых - элемент перечисления двухбайтовый
    PAR_LOG_VARIABLE_ENUM_4   //!< Тип переменной в списке регистрируемых - элемент перечисления четырехбайтовый
} par_log_variable_type_t;

//! Определяет битовые операторы для работы с перечислением enum_type как с флагами
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
ENABLE_FLAGS_FOR_PAR_ENUM(par_date_time_type_t) //!< Определяет битовые операторы для работы с перечислениями как с флагами для par_date_time_type_t
ENABLE_FLAGS_FOR_PAR_ENUM(par_change_flags_t)   //!< Определяет битовые операторы для работы с перечислениями как с флагами для par_change_flags_t
#undef ENABLE_FLAGS_FOR_PAR_ENUM

//! Максимальное количество символов текстовых параметров имитатора
#define PAR_STRING_MAX_LENGTH 0xff

//! Максимальное количество столбцов табличных параметров имитатора
#define PAR_TABLE_COLUMNS_MAX_COUNT 16

//! Широта по умолчанию (в градусах)
#define PAR_LATITUDE_DEFAULT 59.8945501777778

//! Долгота по умолчанию (в градусах)
#define PAR_LONGITUDE_DEFAULT 30.28250567571

//! Параметр имитатора (абстрактный родительский класс)
class par_t {
public:
    /*!
     * Параметр имитатора (абстрактный родительский класс, деструктор)
     */
    virtual ~par_t() = default;

    /*!
     * Возвращает идентификатор списка параметров
     * @return Идентификатор списка параметров
     */
    virtual unsigned char get_list_id() const = 0;                                                     

    /*!
     * Возвращает текстовый идентификатор параметра
     * @return Текстовый идентификатор параметра
     */
    virtual const char* get_text_id() const = 0;                                                       

    /*!
     * Возвращает название
     * @return Название
     */
    virtual const char* get_name() const = 0;                                                         

    /*!
     * Возвращает признак достоверности значения параметра
     * @return Признак достоверности значения параметра
     * @note Если параметр в состоянии PAR_STATUS_TEST или если параметр всегда достоверный, то возвращается true
     */
    virtual bool get_valid() const = 0;                                                                 

    /*!
     * Устанавливает признак достоверности значения параметра
     * @param valid Признак достоверности значения параметра
     */
    virtual void set_valid(const bool valid) = 0;

    /*!
     * Возвращает состояние
     * @return Состояние
     */
    virtual par_status_t get_status() const = 0;                                                        

    /*!
     * Устанавливает cостояние
     * @param status Состояние
     */
    virtual void set_status(const par_status_t status) = 0;

    /*!
     * Возвращает признак недопустимого значения параметра
     * @return Признак недопустимого значения параметра
     */
    virtual bool get_out_of_range() const = 0;                                        

    /*!
     * Устанавливает признак недопустимого значения параметра
     * @param out_of_range Признак недопустимого значения параметра
     */
    virtual void set_out_of_range(const bool out_of_range) = 0;

    /*!
     * Устанавливает значение, признак недопустимого значения и состояние по умолчанию
     */
    virtual void reset() = 0;

    /*!
     * Устанавливает состояние по умолчанию
     */
    virtual void reset_status() = 0;

    /*!
     * Добавляет обработчик события изменения параметра
     * @param handler Добавляемый обработчик события изменения параметра (функция с интерфейсом par_change_handler_t)
     */
    virtual void add_change_handler(void (*handler)(par_t*, const par_change_flags_t)) = 0;//?
    

    /*!
     * Удаляет обработчик события ручного изменения параметра
     * @param handler Удаляемый обработчик события ручного изменения параметра (nullptr - удалить все обработчики)
     */
    virtual void remove_change_handler(void (*handler)(par_t*, const par_change_flags_t) = nullptr) = 0;//?

    /*!
     * Вызывает все обработчики события изменения параметра, установленные с помощью add_change_handler
     * (вызывает все обработчики изменения параметра, даже если параметр не был изменен)
     * @param change_flags Признаки события изменения праметра (набор флагов)
     */
    virtual void invoke_change_handlers(const par_change_flags_t change_flags = static_cast<par_change_flags_t>(PAR_VALUE_CHANGED | PAR_VALID_CHANGED)) = 0;

    /*!
     * Считывает значение и состояние параметра из байтового массива, полученного от GUI-приложения
     * @param[in] array Байтовый массив
     * @param[in] array_size Размер байтового массива
     * @note Используется для приема данных о ручном изменении параметра с помощью GUI-приложения
     */
    virtual void from_byte_array(const void* array, const size_t array_size) = 0;

    /*!
     * Записывает значение и состояние параметра в байтовый массив, формируемый для GUI-приложения
     * @param[out] array Байтовый массив
     * @param[in] array_size Доступный размер байтового массива
     * @return Задействованный при записи размер байтового массива
     * @note Используется для передачи значения и состояния параметра в GUI-приложение
     */
    virtual size_t to_byte_array(void* array, const size_t array_size) const = 0;

    /*!
     * Записывает инициализационные данные параметра в байтовый массив, формируемый для GUI-приложения
     * @param[out] array Байтовый массив
     * @param[in] array_size Доступный размер байтового массива
     * @return Задействованный при записи размер байтового массива
     * @note Используется для начальной передачи информации о параметре в GUI-приложение
     */
    virtual size_t to_init_array(void* array, const size_t array_size) const = 0;

    /*!
     * Устанавливает значение по текстовому запросу (метод для работы с тестирующим приложением)
     * @param text_request Текстовый запрос
     * @return Успешность
     */
    virtual bool set_value_from_text_request(const char* text_request) = 0;                                                

    /*!
     * Добавляет параметр в список регистрируемых
     * @param system_name Название системы на регистрации (nullptr - оставить пустым)
     * @param par_name Название параметра на регистрации (nullptr - использованить наименование параметра)
     */
    virtual void add_to_log_pars(const char* system_name = nullptr, const char* par_name = nullptr) = 0;

    /*!
     * Удаляет параметр из списка регистрируемых
     */
    virtual void remove_from_log_pars() = 0;

    /*!
     * Возвращает номер параметра в списке всех параметров, созданных в приложении (уникальный идентификатор)
     * @return Номер параметра в списке всех параметров, созданных в приложении (нумерация с нуля)
     */
    virtual unsigned int get_index() const = 0;                                                                          

    /*!
     * Возвращает контрольную сумму константной части параметра
     * @return Контрольная сумма константной части параметра
     */
    virtual unsigned int get_checksum() const = 0;

    /*!
     * Копирует значение из другого параметра того же типа
     * @param par Параметр-источник значения
     * @note Параметры должны иметь один тип (текстовые параметры - одинаковый максимальный размер строки)
     */
    virtual void set_value_from(const par_t* par) = 0;

    /*!
     * Сохраняет текущее значение и достоверность параметра (для возможности впоследствии восстановить его вызовом метода load)
     */
    virtual void save() = 0;

    /*!
     * Восстанавливает значение и достоверность параметра, сохраненное ранее вызовом метода save
     */
    virtual void load() = 0;

    /*!
     * Связывает с другим параметром (делает так, что параметры начинают иметь общие переменные данные и что изменение одного приводит к изменению другого)
     * @param par Связываемый параметр
     * @note Параметры должны иметь один тип (текстовые параметры - одинаковый максимальный размер строки)
     */
    virtual void link_with(par_t* par) = 0;

    /*!
     * Сбрасывает связь с другим параметром
     * @param par Отвязываемый параметр
     */
    virtual void unlink_from(par_t* par) = 0;
};

/*!
 * Возвращает указатель на параметр с указанным номером
 * @param index Номер параметра (нумерация с нуля)
 * @return Указатель на параметр (nullptr - параметра с указанным номером не существует)
 */
extern "C" LIBIMIT_API par_t * __stdcall get_par(const unsigned int index);

/*!
 * Возвращает количество параметров, созданных в приложении
 * @return Количество параметров в списке
 */
extern "C" LIBIMIT_API size_t __stdcall get_pars_count();

/*!
 * Возвращает контрольную сумму константной части параметров, созданных в приложении
 * @return Контрольная сумма константной части параметров, созданных в приложении
 */
extern "C" LIBIMIT_API unsigned int __stdcall get_pars_checksum();

/*!
 * Уничтожает все параметры имитатора
 */
extern "C" LIBIMIT_API void __stdcall destroy_all_pars();

/*!
 * Инициализирует регистрацию параметров
 * @param filename Имя файла регистрации параметров (nullptr - отключить регистрацию)
 * @return Успешность
 */
extern "C" LIBIMIT_API unsigned int __stdcall par_log_init(const char* filename);

/*!
 * Очищает файл регистрации параметров
 * @return Успешность
 */
extern "C" LIBIMIT_API unsigned int __stdcall par_log_clear();

/*!
 * Выполняет регистрацию параметров (функция для циклического вызова)
 * @param on Включение регистрации параметров
 */
extern "C" LIBIMIT_API void __stdcall par_log_update(const unsigned int on);

/*!
 * Добавляет переменную в список регистрируемых
 * @param variable_type Тип переменной
 * @param variable_setting Дополнительная настройка переменной (для PAR_LOG_VARIABLE_TEXT - длина текста (передать const uint *), для PAR_LOG_VARIABLE_ENUM_X - список значений перечисления (передать const char *))
 * @param variable_ptr Указатель на переменную
 * @param system_name Название системы на регистрации (nullptr - оставить пустым)
 * @param variable_name Название переменной на регистрации
 */
extern "C" LIBIMIT_API void __stdcall par_log_variable_add(const par_log_variable_type_t variable_type, const void* variable_setting, void* variable_ptr, const char* system_name, const char* variable_name);

/*!
 * Удаляет переменную из списка регистрируемых
 * @param variable_ptr Указатель на переменную (nullptr - удалить все)
 */
extern "C" LIBIMIT_API void __stdcall par_log_variable_remove(void* variable_ptr = nullptr);

//! Обработчик события изменения значения или состояния параметра
typedef void(par_change_handler_t)(par_t*, const par_change_flags_t);

#endif
