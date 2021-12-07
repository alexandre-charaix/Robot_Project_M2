/* 
 * File:   Robot.h
 * Author: CMV_ISEN
 *
 * Created on 7 décembre 2021, 08:37
 */

#ifndef ROBOT_H
#define	ROBOT_H

typedef struct robotStateBITS
{
    union 
    {
        struct 
        {
            unsigned char taskEnCours;
            float vitesseGaucheConsigne;
            float vitesseGaucheCommandeCourante;
            float vitesseDroiteConsigne;
            float vitesseDroiteCommandeCourante;
        };
    };
} ROBOT_STATE_BITS;

extern volatile ROBOT_STATE_BITS robotState;

#endif	/* ROBOT_H */

