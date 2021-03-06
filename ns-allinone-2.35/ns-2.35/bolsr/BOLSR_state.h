/***************************************************************************
 *   Copyright (C) 2004 by Francisco J. Ros                                *
 *   fjrm@dif.um.es                                                        *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.             *
 ***************************************************************************/

///
/// \file	BOLSR_state.h
/// \brief	This header file declares and defines internal state of an BOLSR node.
///

#ifndef __BOLSR_state_h__
#define __BOLSR_state_h__

#include <bolsr/BOLSR_repositories.h>

/// This class encapsulates all data structures needed for maintaining internal state of an BOLSR node.
class BOLSR_state {
	friend class BOLSR;
	
	linkset_t	linkset_;	///< Link Set (RFC 3626, section 4.2.1).
	nbset_t		nbset_;		///< Neighbor Set (RFC 3626, section 4.3.1).
	nb2hopset_t	nb2hopset_;	///< 2-hop Neighbor Set (RFC 3626, section 4.3.2).
	topologyset_t	topologyset_;	///< Topology Set (RFC 3626, section 4.4).
	mprset_t	mprset_;	///< MPR Set (RFC 3626, section 4.3.3).
	mprselset_t	mprselset_;	///< MPR Selector Set (RFC 3626, section 4.3.4).
	dupset_t	dupset_;	///< Duplicate Set (RFC 3626, section 3.4).
	ifaceassocset_t	ifaceassocset_;	///< Interface Association Set (RFC 3626, section 4.1).
	
protected:
	inline	linkset_t&		linkset()	{ return linkset_; }
	inline	mprset_t&		mprset()	{ return mprset_; }
	inline	mprselset_t&		mprselset()	{ return mprselset_; }
	inline	nbset_t&		nbset()		{ return nbset_; }
	inline	nb2hopset_t&		nb2hopset()	{ return nb2hopset_; }
	inline	topologyset_t&		topologyset()	{ return topologyset_; }
	inline	dupset_t&		dupset()	{ return dupset_; }
	inline	ifaceassocset_t&	ifaceassocset()	{ return ifaceassocset_; }
	
	BOLSR_mprsel_tuple*	find_mprsel_tuple(nsaddr_t);
	void			erase_mprsel_tuple(BOLSR_mprsel_tuple*);
	void			erase_mprsel_tuples(nsaddr_t);
	void			insert_mprsel_tuple(BOLSR_mprsel_tuple*);
	
	BOLSR_nb_tuple*		find_nb_tuple(nsaddr_t);
	BOLSR_nb_tuple*		find_sym_nb_tuple(nsaddr_t);
	BOLSR_nb_tuple*		find_nb_tuple(nsaddr_t, u_int8_t);
	void			erase_nb_tuple(BOLSR_nb_tuple*);
	void			erase_nb_tuple(nsaddr_t);
	void			insert_nb_tuple(BOLSR_nb_tuple*);
	
	BOLSR_nb2hop_tuple*	find_nb2hop_tuple(nsaddr_t, nsaddr_t);
	void			erase_nb2hop_tuple(BOLSR_nb2hop_tuple*);
	void			erase_nb2hop_tuples(nsaddr_t);
	void			erase_nb2hop_tuples(nsaddr_t, nsaddr_t);
	void			insert_nb2hop_tuple(BOLSR_nb2hop_tuple*);

	bool			find_mpr_addr(nsaddr_t);
	void			insert_mpr_addr(nsaddr_t);
	void			clear_mprset();
	
	BOLSR_dup_tuple*		find_dup_tuple(nsaddr_t, u_int16_t);
	void			erase_dup_tuple(BOLSR_dup_tuple*);
	void			insert_dup_tuple(BOLSR_dup_tuple*);
	
	BOLSR_link_tuple*	find_link_tuple(nsaddr_t);
	BOLSR_link_tuple*	find_sym_link_tuple(nsaddr_t, double);
	void			erase_link_tuple(BOLSR_link_tuple*);
	void			insert_link_tuple(BOLSR_link_tuple*);

	BOLSR_topology_tuple*	find_topology_tuple(nsaddr_t, nsaddr_t);
	BOLSR_topology_tuple*	find_newer_topology_tuple(nsaddr_t, u_int16_t);
	void			erase_topology_tuple(BOLSR_topology_tuple*);
	void			erase_older_topology_tuples(nsaddr_t, u_int16_t);
	void			insert_topology_tuple(BOLSR_topology_tuple*);
	
	BOLSR_iface_assoc_tuple* find_ifaceassoc_tuple(nsaddr_t);
	void			erase_ifaceassoc_tuple(BOLSR_iface_assoc_tuple*);
	void			insert_ifaceassoc_tuple(BOLSR_iface_assoc_tuple*);
	
};

#endif
