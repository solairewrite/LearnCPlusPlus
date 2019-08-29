# ��7�� STL ����
## 7.1 �����Ĺ�ͨ�����͹�ͨ����
| ���� | Ч�� |
| - | - |
| ContType c | Default ���캯�� |
| ContType c(c2) | Copy ���캯�� |
| ContType c = c2 | Copy ���캯�� |
| ContType c(rv) | Move ���캯�� |
| ContType c = rv | Move ���캯�� |
| ContType c(beg, end) | ����һ������,��[beg, end)�����ڵ�����Ԫ�ؿ���Ϊ��ֵ |
| ContType c(initlist) | ����һ������,���Գ�ֵ��initlist�Ŀ���Ϊ��ֵ |
| ContType c = initlist | ����һ������,���Գ�ֵ��initlist�Ŀ���Ϊ��ֵ |
| c.~ContType() | ɾ������Ԫ��,�ͷ��ڴ� |
| c.empty() | �ж������Ƿ�Ϊ��,�൱��size()==0 |
| c.size() | ���������е�Ԫ������ |
| c.max_size() | ����Ԫ�ص����������� |
| c1 == c2 | �ж�&emsp;!=&emsp;<&emsp;>&emsp;<=&emsp;>= |
| c = c2 | ��c2������Ԫ�ظ�ֵ��c |
| c = rv | ��rvalue rv��move assign��ʽ����c |
| c = initlist | ����ֵ��initlist�е�����Ԫ�ظ�ֵ��c |
| c1.swap(c2) | �û�c1��c2������ |
| swap(c1, c2) | ͬ��,�Ǹ�ȫ�ֺ��� |
| c.begin() | ����һ��iterator,ָ���һ��Ԫ�� |
| c.end() | ����һ��iterator,ָ����ĩԪ�ص���һ��λ�� |
| c.cbegin() | ����һ��const iterator,ָ���һ��Ԫ�� |
| c.cend() | ����һ��const iterator,ָ����ĩԪ�ص���һ��λ�� |
| c.clear() | �Ƴ�����Ԫ��,������Ϊ�� |

| ���� | Ч�� |
| - | - |
| value_type | Ԫ�ص����� |
| reference | Ԫ�ص�reference������ |
| const_reference | ����Ԫ�ص�reference������ |
| iterator | Iterator������ |
| const_iterator | "ָ��ֻ��Ԫ�ص�"iterator������ |
| pointer | "ָ��Ԫ�ص�"pointer������ |
| const_pointer | "ָ��ֻ��Ԫ�ص�"pointer������ |
## 7.2 Array
| ���� | Ч�� |
| - | - |
| c.fill(val) | ��val��ֵ��array c��ÿһ��Ԫ�� |
| c[idx] | ��������idx��ָ��Ԫ��(����鷶Χ) |
| c.at(idx) | ��������idx��ָ��Ԫ��(���idx������Χ���׳�range-error�쳣) |
| c.front() | ���ص�һ��Ԫ��(������Ƿ���ڵ�һԪ��) |
| c.back() | ���ص���ĩԪ��(������Ƿ������ĩԪ��) |