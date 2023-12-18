/*!
 * @file par_title.h
 * @brief Заголовок для списка параметров имитатора
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

 //! Заголовок для списка параметров имитатора
class par_title_t : public par_t {
public:
    /*!
     * Заголовок для списка параметров имитатора (деструктор)
     */
    virtual ~par_title_t() = default;
};

/*!
 * Создает заголовок для списка параметров имитатора
 * @param list_id Идентификатор списка параметров (0 - параметр не принадлежит списку)
 * @param name Текст заголовока
 */
extern "C" LIBIMIT_API par_title_t * __stdcall create_par_title(const unsigned char list_id, const char* name);

/*!
 * Уничтожает заголовок для списка параметров имитатора
 * @par par Уничтожаемый заголовок
 */
extern "C" LIBIMIT_API void __stdcall destroy_par_title(par_title_t * par);

#endif
