package edu.hit.travel.service.impl;

import edu.hit.travel.dao.RouteDao;
import edu.hit.travel.dao.impl.RouteDaoImpl;
import edu.hit.travel.domain.PageBean;
import edu.hit.travel.domain.Route;
import edu.hit.travel.service.RouteService;

import java.util.ArrayList;
import java.util.List;

public class RouteServiceImpl implements RouteService {

    RouteDao routeDao = new RouteDaoImpl();

    @Override
    public PageBean<Route> pageQuery(int cid, int currentPage, int pageSize) {
        PageBean<Route> pageBean = new PageBean<>();
        pageBean.setCurrentPage(currentPage);
        pageBean.setPageSize(pageSize);
        int totalCount = routeDao.findTotalCount(cid);
        pageBean.setTotalCount(totalCount);

        int start = (currentPage - 1) * pageSize;
        List<Route> routes = new ArrayList<>();
        routes = routeDao.findByPage(cid, start, pageSize);
        pageBean.setList(routes);

        int totalPage = totalCount % pageSize == 0 ? totalCount / pageSize : (totalCount / pageSize) + 1;
        pageBean.setTotalPage(totalPage);
        return pageBean;
    }
}