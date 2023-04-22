package edu.hit.travel.service;

import edu.hit.travel.domain.PageBean;
import edu.hit.travel.domain.Route;

public interface RouteService {

    PageBean<Route> pageQuery(int cid, int currentPage, int pageSize);
}