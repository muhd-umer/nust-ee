function tf_ret = my_second_order_tf(zeta, w_n)
    tf_ret = tf(w_n ^ 2, [1, 2 * zeta * w_n, w_n ^ 2]);
end
