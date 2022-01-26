#pragma once

#include <Eigen/Core>

namespace cg {

class Observer {
 public:
  Observer() = default;

  Observer(const Observer &) = delete;

  virtual ~Observer() {}

  virtual Eigen::MatrixXd measurement_function(const Eigen::MatrixXd &mat_x) = 0;

  virtual Eigen::MatrixXd measurement_jacobian(const Eigen::MatrixXd &mat_x, const Eigen::MatrixXd &mat_z) = 0;

  virtual void check_jacobian(const Eigen::MatrixXd &mat_x, const Eigen::MatrixXd &mat_z) = 0;
};
using ObserverPtr = std::shared_ptr<Observer>;

}  // namespace cg