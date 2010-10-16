/*
 * Copyright (C) 2008 The Android Open Source Project
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *  * Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *  * Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in
 *    the documentation and/or other materials provided with the
 *    distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 * "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 * LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 * FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 * COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 * INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 * BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS
 * OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED
 * AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT
 * OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 */
#ifndef _TERMIOS_H_
#define _TERMIOS_H_

#include <sys/cdefs.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <stdint.h>
#include <linux/termios.h>

__BEGIN_DECLS

/* line disciplines */
#define N_TTY		0
#define N_SLIP		1
#define N_MOUSE		2
#define N_PPP		3
#define N_STRIP		4
#define N_AX25		5
#define N_X25		6	/* X.25 async */
#define N_6PACK		7
#define N_MASC		8	/* Reserved for Mobitex module <kaz@cafe.net> */
#define N_R3964		9	/* Reserved for Simatic R3964 module */
#define N_PROFIBUS_FDL	10	/* Reserved for Profibus <Dave@mvhi.com> */
#define N_IRDA		11	/* Linux IrDa - http://irda.sourceforge.net/ */
#define N_SMSBLOCK	12	/* SMS block mode - for talking to GSM data cards about SMS messages */
#define N_HDLC		13	/* synchronous HDLC */
#define N_SYNC_PPP	14
#define N_HCI		15  /* Bluetooth HCI UART */

/* Redefine these to match their ioctl number */
#undef  TCSANOW
#define TCSANOW    TCSETS

#undef  TCSADRAIN
#define TCSADRAIN  TCSETSW

#undef  TCSAFLUSH
#define TCSAFLUSH  TCSETSF

#ifndef N_TTY
#define N_TTY		0
#endif

static __inline__ int tcgetattr(int fd, struct termios *s)
{
    return ioctl(fd, TCGETS, s);
}

static __inline__ int tcsetattr(int fd, int __opt, const struct termios *s)
{
    return ioctl(fd, __opt, (void *)s);
}

static __inline__ int tcflow(int fd, int action)
{
    return ioctl(fd, TCXONC, (void *)(intptr_t)action);
}

static __inline__ int tcflush(int fd, int __queue)
{
    return ioctl(fd, TCFLSH, (void *)(intptr_t)__queue);
}

static __inline__ pid_t tcgetsid(int fd)
{
    pid_t _pid;
    return ioctl(fd, TIOCGSID, &_pid) ? (pid_t)-1 : _pid;
}

static __inline__ int tcsendbreak(int fd, int __duration)
{
    return ioctl(fd, TCSBRKP, (void *)(uintptr_t)__duration);
}

static __inline__ speed_t cfgetospeed(const struct termios *s)
{
    return (speed_t)(s->c_cflag & CBAUD);
}

static __inline__ int cfsetospeed(struct termios *s, speed_t  speed)
{
    s->c_cflag = (s->c_cflag & ~CBAUD) | (speed & CBAUD);
    return 0;
}

static __inline__ speed_t cfgetispeed(const struct termios *s)
{
    return (speed_t)(s->c_cflag & CBAUD);
}

static __inline__ int cfsetispeed(struct termios *s, speed_t  speed)
{
    s->c_cflag = (s->c_cflag & ~CBAUD) | (speed & CBAUD);
  return 0;
}

static __inline__ void cfmakeraw(struct termios *s)
{
    s->c_iflag &= ~(IGNBRK|BRKINT|PARMRK|ISTRIP|INLCR|IGNCR|ICRNL|IXON);
    s->c_oflag &= ~OPOST;
    s->c_lflag &= ~(ECHO|ECHONL|ICANON|ISIG|IEXTEN);
    s->c_cflag &= ~(CSIZE|PARENB);
    s->c_cflag |= CS8;
}

__END_DECLS

#endif /* _TERMIOS_H_ */
