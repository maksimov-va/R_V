/*!
 * @file par_list.h
 * @brief Список параметров имитатора
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
#define  DEBUG

 //! Список параметров имитатора
class par_list_t : public par_t {
public:
    /*!
     * Список параметров имитатора (деструктор)
     */
    virtual ~par_list_t() = default;

    /*!
     * Устанавливает состояние
     * @param status Состояние
    */
    virtual void set_list_status(const par_list_status_t status) = 0;

    /*!
     * Возвращает состояние
     * @return Состояние
    */
    virtual par_list_status_t get_list_status() const = 0;

#ifdef DEBUG
protected:
    par_list_status_t* debug_list_status; //!< Состояние списка (для отладки)
    bool* debug_valid;                    //!< Достоверность (для отладки)
    par_status_t* debug_status;           //!< Состояние параметра (для отладки)
#endif
};

/*!
 * Список параметров имитатора (вертикальный отступ в списке параметров)
 * @param list_id Идентификатор списка параметров (ненулевой)
 * @param name Название списка параметров
 */
extern "C" LIBIMIT_API par_list_t * __stdcall create_par_list(const unsigned char list_id, const char* name);

/*!
 * Уничтожает список параметров имитатора
 * @par par Уничтожаемый список
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_list(par_list_t * par);

#endif
