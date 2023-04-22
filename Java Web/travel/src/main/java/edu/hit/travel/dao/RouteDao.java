package edu.hit.travel.dao;

import edu.hit.travel.domain.Route;

import java.util.List;

public interface RouteDao {
    int findTotalCount(int cid);

    List<Route> findByPage(int cid, int start, int pageSize);
}