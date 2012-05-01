/*
 * pet.cpp - Pet class
 */

#include <iostream>
#include "pet.h"

CPet::CPet(char* nom, int yrs)
{
    if ((int)strlen(nom) > NameLength)
        fprintf(stderr, "Warning: Length of pet name is too long (%d char)\n", (int)strlen(nom));
    strncpy(m_name, nom, strlen(m_name));
    m_age = yrs;
    m_hurt_legs = 0;
}

CPet::~CPet()
{
    printf("Dying...\n");
}

int CPet::SetAge(int yrs)
{
    m_age = yrs;
    return(m_age);
}

int CPet::GetAge()
{
    return(m_age);
}

int CPet::HappyBirthday()
{
    SetAge(GetAge() + 1);
    return(m_age);
}

char* CPet::GetName()
{
    return(m_name);
}

void CPet::HurtLeg(char *leg)
{
    if (strcmp(leg, "LF") == 0)
        m_hurt_legs |= LFLeg;
    else if (strcmp(leg, "RF") == 0)
        m_hurt_legs |= RFLeg;
    else if (strcmp(leg, "RR") == 0)
        m_hurt_legs |= RRLeg;
    else if (strcmp(leg, "LR") == 0)
        m_hurt_legs |= LRLeg;
    else
        fprintf(stderr, "Warning: Invalid leg specified to HurtLeg: '%s'\n", leg);
}

void CPet::HealLeg(char *leg)
{
    if (strcmp(leg, "LF") == 0)
        m_hurt_legs &= ~LFLeg;
    else if (strcmp(leg, "RF") == 0)
        m_hurt_legs &= ~RFLeg;
    else if (strcmp(leg, "RR") == 0)
        m_hurt_legs &= ~RRLeg;
    else if (strcmp(leg, "LR") == 0)
        m_hurt_legs &= ~LRLeg;
    else
        fprintf(stderr, "Warning: Invalid leg specified to HurtLeg: '%s'\n", leg);
}

void CPet::LegStatus()
{
    printf("=========== Leg Status ============\n");
    if ((m_hurt_legs & LFLeg) == LFLeg)
        printf("Left front leg is HURT\n");
    else
        printf("Left front leg is OK\n");

    if ((m_hurt_legs & RFLeg) == RFLeg)
        printf("Right front leg is HURT\n");
    else
        printf("Right front leg is OK\n");

    if ((m_hurt_legs & LRLeg) == LRLeg)
        printf("Left rear leg is HURT\n");
    else
        printf("Left rear leg is OK\n");

    if ((m_hurt_legs & RRLeg) == RRLeg)
        printf("Right rear leg is HURT\n");
    else
        printf("Right rear leg is OK\n");
}


