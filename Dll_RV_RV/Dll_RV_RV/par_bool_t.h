/*!
 * @file par_bool.h
 * @brief Булевый параметр имитатора
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
#include "par_t.h"
#define DEBUG

 //! Булевый параметр имитатора
class par_bool_t : public par_t {
public:
    /*!
     * Булевый параметр имитатора (деструктор)
     */
    virtual ~par_bool_t() = default;

    /*!
     * Возвращает значение
     * @return Значение
     */
    virtual bool get_value() const = 0;

    /*!
     * Устанавливает значение
     * @param value Значение
     */
    virtual void set_value(const bool value) = 0;

    /*!
     * Возвращает значение по умолчанию
     * @return Значение по умолчанию
     */
    virtual bool get_default_value() const = 0;

    /*!
     * Возвращает тип кнопки
     * @return Тип кнопки
     */
    virtual par_bool_button_type_t get_button_type() const = 0;

#ifdef DEBUG
protected:
    bool* debug_value;          //!< Значение (для отладки)
    bool* debug_valid;          //!< Достоверность (для отладки)
    par_status_t* debug_status; //!< Состояние (для отладки)
#endif
};

/*!
 * Создает булевый параметр имитатора
 * @param list_id Идентификатор списка параметров (0 - параметр не принадлежит списку)
 * @param text_id Текстовый идентификатор параметра
 * @param name Название
 * @param button_type Тип кнопки (par_bool_button_type_t)
 * @param default_value Значение по умолчанию
 * @param invalid_available Доступность состояния "не достоверный" (par_invalid_available_t)
 */
extern "C" LIBIMIT_API par_bool_t * __stdcall create_par_bool(const unsigned char list_id, const char* text_id, const char* name, const unsigned int button_type = PAR_BOOL_BUTTON_LARGE, const bool default_value = false, const unsigned int invalid_available = PAR_ALWAYS_VALID);

/*!
 * Уничтожает булевый параметр имитатора
 * @par par Уничтожаемый параметр
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_bool(par_bool_t * par);

#endif
